//青春·盛放
class Gmap4 extends egret.Sprite{
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
    private _timer2: egret.Timer;
    private memnum: number=0;
                    
    private init()
    { 
        this.x = 0;
        this.y = 0;
        this.width = 480;
        this.height = 800;
        
        this.bg = new egret.Bitmap();
        this.bg.texture= RES.getRes(DataStruct.levelmapbg[4]);
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
        this.textArea.text = "青春·盛放";
                
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
    private getuiu() {
        this.getui.texture = RES.getRes("getui_up_png");
    }
 
    private update()
    {
        for(var i = 0;i < this.walls.length;i++)
        { 
            this.walls[i].move_wall();
        }
                                              
        this.role.updateRole_l0(this.walls,this.door,this.balls);
        if(this.role.isOver())
        {
            this._timer0.stop();
        }
        //判读是否进入下一关： 
        if(this.door != null && this.door.parent != null) {
            if(this.role.hitgate(this.door)) {             
                DataStruct.levelNow = this.door.getLabel();
                DataStruct.levelclock[DataStruct.levelNow] = true;//若通关此关卡解锁
                this._timer0.stop();
                DataStruct.stage.dispatchEvent(new egret.Event("nowlevel"));
            }
        }
        //判断小球是否被吃掉
        for(var i = 0;i < this.balls.length;i++)
        {
            if(this.balls[i].get_isAte()==true) {
                if(this.balls[i].parent != null) {
                    this.removeChild(this.balls[i]);
                    this.memnum++;
                }
            }
        }
        if((this.balls[0].get_isAte() == true || this.balls[1].get_isAte() == true) && (this.balls[2].get_isAte() == false))
        {
            this._timer1 = new egret.Timer(2000,0);
            this._timer1.addEventListener(egret.TimerEvent.TIMER,this.over,this);
            this._timer1.start();   
        }
        console.log("memnum",this.memnum);
        if(this.memnum == 3)
        {
            this.resetwall();
            this.memnum = 0;
        }
    }
    private create_l0()
    {                                  
        this.role = new Role(280,280,0);
        this.addChild(this.role);
                                            
        this.walls = [];
        var wall0: Obstacle = new Obstacle(0,240,330,false,0,0,0);//right horizontal
        var wall1: Obstacle = new Obstacle(0,120,300,false,0,0,0);//left horizontal
        var wall2: Obstacle = new Obstacle(1,240,210,false,0,0,0);//right vertical
        var wall3: Obstacle = new Obstacle(1,210,330,false,0,0,0);//left vertical
        var wall4: Obstacle = new Obstacle(1,0,0,true,1,-120,600);
        var wall5: Obstacle = new Obstacle(1,450,480,true,0,-120,600);
                                       
        this.walls.push(wall0);
        this.walls.push(wall1);
        this.walls.push(wall2);
        this.walls.push(wall3);
        this.walls.push(wall4);
        this.walls.push(wall5);

               
        for(var i = 0;i < this.walls.length;i++)
        { 
            this.addChild(this.walls[i]);
        }                                                   
        this.balls = [];
        var ball0: MemoryBall = new MemoryBall(180,260,13,0);
        var ball1: MemoryBall = new MemoryBall(170,360,14,0);
        var ball2: MemoryBall = new MemoryBall(240,380,15,0);
        this.balls.push(ball0);
        this.balls.push(ball1);
        this.balls.push(ball2);
        for(var i = 0;i < this.balls.length;i++) {
            this.addChild(this.balls[i]);
        }                                      
        this.door = new TransGate(5,190,100);
                
        this.role.setWallID = 0;
        this.role.wal_to_rolex = this.role.x - this.walls[0].x;
        this.role.wal_to_roley = this.role.y - this.walls[0].y;
    }
    private resetwall()//重置墙壁数据
    { 
        for(var i = 0;i < this.walls.length;i++) {
            if(i != this.role.setWallID) {
                this.walls[i].x = -120;
                this.walls[i].y = -120;
                this.addChild(this.door);
                this.textArea.text="当老照片褪了色，恍惚间已经走过了那段岁月";
            }
        }
    }
    private over()
    { 
        this.textArea.text = "毫无准备的青春，在与命运的赌博中失散";
        this._timer2 = new egret.Timer(20000,1);
        this._timer2.addEventListener(egret.TimerEvent.TIMER,this.overnow,this);
        this._timer2.start();       
    }
    private overnow()
    { 
        DataStruct.stage.dispatchEvent(new egret.Event("gameover"));
        this._timer1.stop();
    }   
}
