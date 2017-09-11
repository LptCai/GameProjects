//邂逅·爱情
class Gmap5 extends egret.Sprite{
    public constructor() {
        super();
        this.init();
    }
    private role: Role;
    private walls: Obstacle[];
    private balls: MemoryBall[];
    private door: TransGate;
    private textArea: egret.TextField;
    private bg: egret.Bitmap;
    private Gcontrol: ControlArea;
    private music: Music;
    private getui: egret.Bitmap;
    private _timer0: egret.Timer;
    private _timer1: egret.Timer;
    private memnum: number = 0;
    private _over: boolean = false;//防止两次发送结束事件
                        
    private init()
    { 
        this.x = 0;
        this.y = 0;
        this.width = 480;
        this.height = 800;
                
        this.bg = new egret.Bitmap();
        this.bg.texture= RES.getRes(DataStruct.levelmapbg[5]);
        this.bg.x = 0;
        this.bg.y = 0;
        this.bg.width = DataStruct.stageW;
        this.bg.height = DataStruct.stageH;
        this.addChild(this.bg);
                                                
        //感应区域加载：
        this.Gcontrol = new ControlArea();
        this.Gcontrol.x = 180;
        this.Gcontrol.y = 680;
        this.Gcontrol.width = 120;
        this.Gcontrol.height = 120;
        this.addChild(this.Gcontrol);
                                                
        //音乐控件
        this.music = new Music();
        this.addChild(this.music);
                                                
        //UI调用
        this.getui = new egret.Bitmap();
        this.getui.texture = RES.getRes("getui_up_png");
        this.getui.x = 440;
        this.getui.y = 720;
        this.getui.width = 40;
        this.getui.height = 40;
        this.addChild(this.getui);
        this.getui.touchEnabled = true;
        this.getui.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.getuid,this);
        this.getui.addEventListener(egret.TouchEvent.TOUCH_END,this.getuiu,this);
                                                
        this.create_l0();
                                         
        this.textArea = new egret.TextField();
        this.textArea.x = 40;
        this.textArea.y = 10;
        this.textArea.width = 400;
        this.textArea.text = "邂逅·爱情";
                        
        this.textArea.textColor = 0xffffff;
        this.textArea.size = 15;
        this.textArea.background = false;
        this.textArea.fontFamily = "华文楷体";
        this.textArea.textAlign =egret.HorizontalAlign.CENTER;
        this.addChild(this.textArea);       
                        
        //设置定时器刷新动画
        this._timer0 = new egret.Timer(30,0);
        this._timer0.addEventListener(egret.TimerEvent.TIMER,this.update,this);
        this._timer0.start();   
        
    }
    private getuid()
    { 
        this.getui.texture = RES.getRes("getui_down_png");
        this._timer0.stop();
        DataStruct.stage.dispatchEvent(new egret.Event("gameover"));
    }
    private getuiu()
    { 
        this.getui.texture = RES.getRes("getui_up_png");
    }
    private update()
    {
        for(var i = 0;i < this.walls.length;i++)
        { 
            this.walls[i].move_wall();
        }
                                                                      
        this.role.updateRole_l0(this.walls,this.door,this.balls);
        if(this._over == false) {
            if(this.role.isOver()) {
                this._timer0.stop();
                this._over = true;
            }
        }
        //判读是否进入下一关： 
        if(this.door != null && this.door.parent != null) {
            if(this.role.hitgate(this.door)) {
                DataStruct.levelNow = this.door.getLabel();
                this._timer0.stop();
                DataStruct.stage.dispatchEvent(new egret.Event("nowlevel"));
            }
        }
        //【判断小球是否被吃掉
        for(var i = 0;i < this.balls.length;i++)
        {
            if(this.balls[i].get_isAte()==true) {
                if(this.balls[i].parent != null) {
                    this.removeChild(this.balls[i]);
                    this.memnum++;
                }
            }
        }
        if(this.memnum == 3)
        { 
            this.clearwall();
            this.addChild(this.door);
            this.textArea.text = "爱情是红白玫瑰的悲剧，也许选择离开更好";
            this.memnum = 0;
        }
        if(this.balls[0].get_isAte())
        { 
            this.walls[7].y = -130;
            this.walls[8].y = -120;
            this.textArea.text = "爱也可以是终点";
            this._timer1 = new egret.Timer(3000,1);
            this._timer1.addEventListener(egret.TimerEvent.TIMER,this.over,this);
            this._timer1.start();   
        }
    }
    private create_l0()
    { 
                                                      
        this.role = new Role(180,110,0);
        this.addChild(this.role);
                                                        
        this.walls = [];
        var wall0: Obstacle = new Obstacle(0,180,230,false,0,0,0);
        var wall1: Obstacle = new Obstacle(0,180,380,false,0,0,0);
        var wall2: Obstacle = new Obstacle(1,150,260,false,0,0,0);
        var wall3: Obstacle = new Obstacle(1,300,260,false,0,0,0);
        var wall4: Obstacle = new Obstacle(0,360,570,true,2,120,360);
        var wall5: Obstacle = new Obstacle(1,0,130,true,0,130,480);
        var wall6: Obstacle = new Obstacle(1,450,130,true,0,130,480);
        
        this.walls.push(wall0);
        this.walls.push(wall1);
        this.walls.push(wall2);
        this.walls.push(wall3);
        this.walls.push(wall4);
        this.walls.push(wall5);
        this.walls.push(wall6);
                
        for(var i = 0;i < this.walls.length;i++)
        { 
            this.addChild(this.walls[i]);
        }
                                                                        
        this.balls = [];
        var ball0: MemoryBall = new MemoryBall(180,260,16,0);//inner
        var ball1: MemoryBall = new MemoryBall(110,280,16,0);//左
        var ball2: MemoryBall = new MemoryBall(330,290,17,0);//right
        var ball3: MemoryBall = new MemoryBall(200,410,18,0);//down
        this.balls.push(ball0);
        this.balls.push(ball1);
        this.balls.push(ball2);
        this.balls.push(ball3);
        
        for(var i = 0;i < this.balls.length;i++) {
            this.addChild(this.balls[i]);
        }
                                                          
        this.door = new TransGate(6,190,100);
                            
        this.role.setWallID = 0;
        this.role.wal_to_rolex = this.role.x - this.walls[0].x;
        this.role.wal_to_roley = this.role.x - this.walls[0].y;
    }
    private clearwall()
    { 
        this.walls[1].y = 800;
        this.walls[5].x = -120;
        this.walls[6].x = 600;
        var wall7: Obstacle = new Obstacle(0,0,140,false,0,0,0);
        var wall8: Obstacle = new Obstacle(0,360,140,false,0,0,0);
        this.walls.push(wall7);
        this.walls.push(wall8);
        this.addChild(this.walls[7]);
        this.addChild(this.walls[8]);
    }
    private over()
    { 
        if(this._over == false)
        { 
            this._over = true;
            DataStruct.stage.dispatchEvent(new egret.Event("gameover"));
        }
    }
                            
}
