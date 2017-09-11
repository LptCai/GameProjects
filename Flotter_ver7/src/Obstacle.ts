
class Obstacle extends egret.Sprite{
	public constructor(type:number,x:number,y:number,move:boolean,dir:number,movepace_d:number,movepace_u:number) {
        super();
        this.init(type,x,y,move,dir,movepace_d,movepace_u);
	}
    private wall: egret.Bitmap;
    public canmove: boolean;//墙壁是否移动的值
    public movedir: number;//移动方向
    public movepace_d: number;//移动最小坐标位置
    public movepace_u: number;//移动最大坐标位置
    private _timer0: egret.Timer;//设置定时器自身更新移动位置
   
    private init(type:number,x:number,y:number,move:boolean,dir:number,movepace_d:number,movepace_u:number)
    { 
        this.x = x;
        this.y = y;
        
        
        this.movepace_d = movepace_d;
        this.movepace_u = movepace_u;
        this.canmove = move;
        this.movedir = dir;
        
        this.wall = new egret.Bitmap();
        if(type == 0) {
            this.wall.texture= RES.getRes("wall0_png");
            this.wall.x = 0;
            this.wall.y = 0;
            this.wall.width = 120;
            this.wall.height = 30;
            this.width = 120;
            this.height = 30;
        } else if(type == 1) {
            this.wall = new egret.Bitmap();
            this.wall .texture= RES.getRes("wall1_png");
            this.wall.x = 0;
            this.wall.y = 0;
            this.wall.width = 30;
            this.wall.height = 120;
            this.width = 30;
            this.height = 120;
        }
        this.addChild(this.wall); 
    }
    public move_wall() {
        if(this.canmove == true) {
            switch(this.movedir) {
                case 0://下                 
                     this.y = DataStruct.movespeed + this.y;
                     if(this.y + this.height > this.movepace_u)
                     { 
                         this.movedir = 1;
                     }
                    break;
                case 1://shang
                     this.y =- DataStruct.movespeed + this.y;
                     if(this.y<this.movepace_d)
                    { 
                         this.movedir = 0;
                    }
                    break;
                case 2://zuo
                     this.x = -DataStruct.movespeed + this.x;
                     if(this.x + this.width < this.movepace_d)
                     { 
                        this.movedir = 3;
                     }
                    break;
                case 3://right
                    this.x = DataStruct.movespeed + this.x;
                    if(this.x >this.movepace_u)
                    { 
                          this.movedir = 2;
                    }
                    break;
                    
            }
        }
    }    
}
