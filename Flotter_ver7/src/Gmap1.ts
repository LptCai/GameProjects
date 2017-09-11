//新生·希冀
class Gmap1 extends egret.Sprite{
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
    public _timer0: egret.Timer;
    private _timer1: egret.Timer;
    private memnum: number = 0;
                        
    private init()
    { 
        this.x = 0;
        this.y = 0;
        this.width = 480;
        this.height = 800;
                
        this.bg = new egret.Bitmap();
        this.bg.texture= RES.getRes(DataStruct.levelmapbg[1]);
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
        //由于关卡内部有多个计时器且开启时间与记录均不定，所以在调用UI界面以及返回当前界面时
        //不好判断计时器的开启与关闭状态，故此按钮做退出游戏按钮使用
                                                
        this.create_l0();
                                         
        this.textArea = new egret.TextField();
        this.textArea.x = 40;
        this.textArea.y = 10;
        this.textArea.width = 400;
        this.textArea.text = "新生·希冀";
                        
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
        console.log("being updated");
        for(var i = 0;i < this.walls.length;i++)
        { 
            this.walls[i].move_wall();
        }                                                    
        this.role.updateRole_l0(this.walls,this.door,this.balls);
        if(this.role.isOver())
        {
            this._timer0.stop();
            console.log("overgamellll");
            console.log("rolex:",this.role.x);
            console.log("roley:",this.role.y);
        }
        //判读是否进入下一关： 
        if(this.role.hitgate(this.door))
        { 
            DataStruct.levelNow =this.door.getLabel();
            DataStruct.levelclock[DataStruct.levelNow] = true;
            this._timer0.stop();
            DataStruct.stage.dispatchEvent(new egret.Event("nowlevel"));
        }
        //【判断小球是否被吃掉
        for(var i = 0;i < this.balls.length;i++)
        {
            if(this.balls[i].get_isAte()==true) {
                if(this.balls[i].parent != null) {
                    this.removeChild(this.balls[i]);
                    this.textArea.text = DataStruct.memorytex[this.balls[i].textlabel];
                    this.memnum++;
                }
            }
        }
        //更新文字：
        if(this.memnum == 3)
        { 
            this._timer1 = new egret.Timer(30,0);
            this._timer1.addEventListener(egret.TimerEvent.TIMER,this.removewall,this);
            this._timer1.start();  
            this.memnum = 0;
            this.textArea.text="守护的围墙破碎，心灵的依傍还在，终走不出"
        }      
    }
    private create_l0()
    { 
                                                     
        this.walls = [];
        var wall0: Obstacle = new Obstacle(0,60,120,false,0,0,0);//up lfet
        var wall1: Obstacle = new Obstacle(0,180,120,false,0,0,0);//up middle
        var wall2: Obstacle = new Obstacle(0,300,120,false,0,0,0);//up right
        var wall3: Obstacle = new Obstacle(0,60,510,false,0,0,0);//down left
        var wall4: Obstacle = new Obstacle(0,180,510,false,0,0,0);//down middle
        var wall5: Obstacle = new Obstacle(0,300,510,false,0,0,0);//down right
        var wall6: Obstacle = new Obstacle(1,60,150,false,0,0,0);//left up
        var wall7: Obstacle = new Obstacle(1,60,270,false,0,0,0);//left middle
        var wall8: Obstacle = new Obstacle(1,60,390,false,0,0,0);//left down
        var wall9: Obstacle = new Obstacle(1,390,150,false,0,0,0);//right up
        var wall10: Obstacle = new Obstacle(1,390,270,false,0,0,0);//right middle
        var wall11: Obstacle = new Obstacle(1,390,390,false,0,0,0);//right down
                                                                             
        this.walls.push(wall0);
        this.walls.push(wall1);
        this.walls.push(wall2);
        this.walls.push(wall3);
        this.walls.push(wall4);
        this.walls.push(wall5);
        this.walls.push(wall6);
        this.walls.push(wall7);
        this.walls.push(wall8);
        this.walls.push(wall9);
        this.walls.push(wall10);
        this.walls.push(wall11);
        for(var i = 0;i < this.walls.length;i++)
        { 
            this.addChild(this.walls[i]);
        }
                                                                        
        this.balls = [];
        var ball0: MemoryBall = new MemoryBall(300,150,4,0);
        var ball1: MemoryBall = new MemoryBall(90,240,5,0);
        var ball2: MemoryBall = new MemoryBall(350,250,5,0);
        this.balls.push(ball0);
        this.balls.push(ball1);
        this.balls.push(ball2);
        for(var i = 0;i < this.balls.length;i++) {
            this.addChild(this.balls[i]);
        }
        this.door = new TransGate(2,190,550);
                
        this.role = new Role(300,320,0);
        this.addChild(this.role);
                            
        this.role.setWallID = 0;
        this.role.wal_to_rolex = this.role.x - this.walls[0].x;
        this.role.wal_to_roley = this.role.x - this.walls[0].y;
    }
    private removewall()
    { 
        this.walls[1].y -= 2;
        this.walls[4].y += 3;
        this.walls[7].x -= 2;
        this.walls[10].x += 2;
        if(this.walls[1].y <= -30 && this.walls[4].y >= 800 && this.walls[7].x <= -30 && this.walls[10].x >= 480)
        { 
            this._timer1.stop()
                var ball3: MemoryBall = new MemoryBall(60,80,6,0);
                var ball4: MemoryBall = new MemoryBall(350,80,7,0);
                this.balls.push(ball3);
                this.balls.push(ball4);
                this.addChild(this.balls[3]);
                this.addChild(this.balls[4]);
                            
                //生成两堵移动的墙壁
                var wall12: Obstacle = new Obstacle(0,-120,20,true,3,-120,480);
                var wall13: Obstacle = new Obstacle(0,-120,300,true,3,-120,480);
                this.walls.push(wall12);
                this.walls.push(wall13);
                this.addChild(this.walls[12]);
                this.addChild(this.walls[13]);
                            
                //画门                                       
                this.addChild(this.door);   
                            
                this.textArea.text="你踩着巫师的扁担走出城堡"
            }        
        }                       
   
}
