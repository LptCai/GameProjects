//成长·选择
class Gmap2 extends egret.Sprite {
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
    private door_open: boolean;
    private memnum: number;
    private atenum: number=0;
    private init()
    { 
        this.x = 0;
        this.y = 0;
        this.width = 480;
        this.height = 800;
        this.door_open = true;
        
        this.bg = new egret.Bitmap();
        this.bg.texture= RES.getRes(DataStruct.levelmapbg[2]);
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
        this.textArea.text = "成长·选择";
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
        this.role.updateRole_l0(this.walls,this.door,this.balls);
        if(this.role.isOver())
        {
            this._timer0.stop();
        }
        
        if(this.textArea.text=="你忍不住回首，流连，至于困在这片森林")
        { 
            if(this.door !=null&&this.door.parent!=null) {
                if(this.balls[0].get_isAte() == true) {
                    this.removeChild(this.door);
                }
            }
        }
        //判读是否进入下一关：
        if(this.door != null) {
            if(this.role.hitgate(this.door)) {
                DataStruct.levelNow = this.door.getLabel();
                DataStruct.levelclock[DataStruct.levelNow] = true;//若通关此关卡解锁
                this._timer0.stop();
                //派是啊金
                DataStruct.stage.dispatchEvent(new egret.Event("nowlevel"));
            }
        }
        //【判断小球是否被吃掉
        for(var i = 0;i < this.balls.length;i++)
        {
            if(this.balls[i].get_isAte()==true) {
                if(this.balls[i].parent != null) {
                    this.removeChild(this.balls[i]);
                    if(i == 1) {
                        this.textArea.text = DataStruct.memorytex[this.balls[i].textlabel];
                    } else {
                        this.textArea.text = "你在魔法森林里游弋，她给你无尽的宠溺";
                        //设置定时器刷新动画——产生新的记忆球
                        this._timer1 = new egret.Timer(2000,1);
                        this._timer1.addEventListener(egret.TimerEvent.TIMER,this.nextball,this);
                        this._timer1.start();
                    }
                }               
            }
        }
        if(this.atenum >= 2)
        { 
            this.addChild(this.door);
            this.textArea.text = "也许你不舍湖光山色，踏过那道门，逃开巫师的蛊惑";
        }
    }
        private create_l0()
        { 
            
            this.role = new Role(80,50,0);
            this.addChild(this.role);
            
            this.walls = [];
            var wall0: Obstacle = new Obstacle(0,40,100,false,0,0,0);//left horizontal up
            var wall1: Obstacle = new Obstacle(0,40,600,false,0,0,0);//left hozirontal down
            var wall2: Obstacle = new Obstacle(1,360,60,false,0,0,0);//right vertical
            var wall3: Obstacle = new Obstacle(0,320,400,false,0,0,0);//right horizontal 
            var wall4: Obstacle = new Obstacle(1,80,360,false,0,0,0);//left vertical
            this.walls.push(wall0);
            this.walls.push(wall1);
            this.walls.push(wall2);
            this.walls.push(wall3);
            this.walls.push(wall4);
            for(var i = 0;i < this.walls.length;i++)
            { 
                this.addChild(this.walls[i]);               
            }
                
                this.balls = [];
                var ball0: MemoryBall = new MemoryBall(80,130,0,0);
                var ball1: MemoryBall = new MemoryBall(330,360,8,0);
                this.balls.push(ball0);
                this.balls.push(ball1);
                for(var i = 0;i < this.balls.length;i++) {
                    this.addChild(this.balls[i]);
                }
                
                this.door = new TransGate(3,350,560);          
                this.role.setWallID = 0;
                this.role.wal_to_rolex = this.role.x - this.walls[0].x;
                this.role.wal_to_roley = this.role.y - this.walls[0].y;               
     }                
      private nextball()
      {           
          if(this.balls[0].get_isAte() == true) {
              this.addChild(this.balls[0]);
              this.balls[0].set_isAte(false);
              this.textArea.text = "你忍不住回首，流连，至于困在这片森林";
              this._timer1.stop();
              this.atenum++;
          }      
      
      }   
            
}
     