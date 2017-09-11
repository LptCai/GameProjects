class Role extends egret.Sprite{
	public constructor(x:number,y:number,dir:number) {
        super();
        this.init(x,y,dir);
	}
	
    private RoleTex: egret.Bitmap;
    private rotate: egret.MovieClip;
    private dir: number;
    private speedx: number;
    private speedy: number;
    private isStill: boolean = true;
    public setWallID: number;
    public wal_to_rolex: number;
    public wal_to_roley: number;
    
    private init(x:number,y:number,dir:number)
    { 
        this.dir = dir;
        this.RoleTex = new egret.Bitmap();
        this.RoleTex.texture = RES.getRes(DataStruct.roletex[this.dir]);
        this.RoleTex.x = 0;
        this.RoleTex.y = 0;
        this.RoleTex.width = 50;
        this.RoleTex.height = 50; 
        this.addChild(this.RoleTex);
        this.speedx = 0;
        this.speedy = 0;
        
        this.x = x;
        this.y = y;
        this.width = 50;
        this.height = 50;
    }
    public getDir()
    {
        return this.dir;
    }
    public fall(wall:Obstacle[])//物体只受重力运动
    {   
        var preX: number = this.x;
        var preY: number = this.y;
        this.speedx += DataStruct.Gx;
        this.speedy += DataStruct.Gy;
        this.x += this.speedx;
        this.y += this.speedy;
        //检测是否落地
        this.FalltoWall(wall,preX,preY,this.x,this.y);
    }
    //检测物体是否受到支持力而落地
    public isSupppported(wall:Obstacle[]):boolean
    { 
        switch(DataStruct.Gdir)
        {           
            case 0://检测上面是否受到支持力
                for(var i: number = 0;i < wall.length;i++)
                { 
                    if(wall[i].y +wall[i].height>= this.y &&wall[i].y<=this.y)
                    { 
                        if((this.x +this.width-5 >= wall[i].x) && (this.x +5) <= (wall[i].x + wall[i].width))
                        {                          
                            return true;
                        }
                    }
                }
                break;
            case 1://检测下方是否受到支持力
            for(var i: number = 0;i < wall.length;i++)
            { 
                if(wall[i].y<= (this.y + this.height)&&wall[i].height+wall[i].y>=(this.y + this.height))
                { 
                    if((this.x + this.width -5 >= wall[i].x) && (this.x+5) <= (wall[i].x + wall[i].width))
                    { 
                        return true;
                    }
                }
            }
                break;
            case 2://检测左边是否受到支持力
            for(var i: number = 0;i < wall.length;i++)
            { 
                if(wall[i].x+wall[i].width >=this.x&&this.x>=wall[i].x)
                { 
                    if((this.y + this.height -5 >= wall[i].y) && (this.y + 5) <= (wall[i].y + wall[i].height))
                    { 
                        return true;
                    }
                }
            }
                break;
            case 3://检测右侧是否受支持力
            for(var i: number = 0;i < wall.length;i++)
            { 
                if(wall[i].x <= (this.x + this.width)&&wall[i].x+wall[i].width>=(this.x + this.width))
                { 
                    if((this.y + this.height -5 >= wall[i].y) && (this.y + 5) <= (wall[i].y + wall[i].height))
                    {                       
                        return true;
                    }
                }
            }
         
                break;
            default:
                break;
        }
        return false;
    }
    //判断游戏是否结束，角色出框则游戏结束
    public isOver():boolean
    { 
        if((this.x <= -this.width/2 || this.x >= (DataStruct.stageW))||(this.y<=-this.height/2)||(this.y>DataStruct.stageH))
        { 
            DataStruct.stage.dispatchEvent(new egret.Event("gameover"));
            return true;
        }
        return false;
    }
    //更新与角色相关的属性
    public updateRole_l0(wall:Obstacle[],door:TransGate,ball:MemoryBall[])
    { 
        this.getMemory(ball);
        if(this.isSupppported(wall)) {
            this.isStill = true;  
            this.move_as_wall(wall);//落地后随之移动函数
        } else { 
            this.isStill = false;
            this.fall(wall);
        }       
        if(this.isStill == true) {
            this.speedx = 0;
            this.speedy = 0;
        }
    }
   
    public FalltoWall(wall:Obstacle[],xPre:number,yPre:number,xNow:number,yNow:number)//检测物体在掉落过程中是否落地
    { 
        var dx:number= xNow - xPre;
        var dy: number = yNow - yPre;
        var flag: number = 0;
        var settleID: number[]=[];//为防止两个墙壁距离较近，物体发生多次掉落，设置数组记录可落位置，选取最佳落点                                            
       if(dx>0&&dy==0)
       {
                flag=14;                                                          //x轴正向——1、4象限
       }else if(dx<0&&dy==0)
       {
                flag=23;                                                          //x轴负方向——2，3象限
        }else if(dx==0&&dy<0)
        {
                flag=12;                                                           //Y轴正方向——1，2象限
        }else if(dx==0&&dy>0)
        {
                flag=34;                                                          //Y轴负向——3，4象限
        }
            switch(flag)
            {               
                case 14:
                    //根据即将进入的位置判断落地情况x上半轴，检测右落地
                    var t = 0;
                    for(var i = 0;i < wall.length;i++) {
                        if(this.RCollidewall(wall[i],xPre,yPre,xNow,yNow)) {
                            settleID.push(i);                         
                            t++;
                        }
                    }
                    if(t > 0) {
                        var id = settleID[0];
                        for(var j = 0;j < settleID.length;j++) {
                            if(wall[settleID[j]].x <= wall[id].x)
                            { 
                                id = settleID[j];
                            }
                        }
                       this.falltoR(wall[id]);
                       this.re_Settledown(wall,id);
                       this.isStill = true;
                    }
                    break;
                case 23:
                    var t = 0;
                    for(var i = 0;i < wall.length;i++) {
                         if(this.LCollidewall(wall[i],xPre,yPre,xNow,yNow)) {
                              settleID.push(i);                         
                              t++;
                         }
                    }
                    if(t > 0) {
                        var id = settleID[0];
                        for(var j = 1;j < settleID.length;j++) {
                            if(wall[settleID[j]].x+wall[settleID[j]].width >= wall[id].x+wall[id].width)
                            { 
                                id = settleID[j];
                            }
                         }
                         this.falltoL(wall[id]);
                         this.re_Settledown(wall,id);
                         this.isStill = true;
                    }
                    break;
                case 12:
                    var t = 0;
                    for(var i = 0;i < wall.length;i++) {
                        if(this.UCollidewall(wall[i],xPre,yPre,xNow,yNow)) {
                            settleID.push(i);
                            t++;                           
                        }
                    }
                    if(t > 0)
                    { 
                        var id = settleID[0];
                        for(var j = 1;j < settleID.length;j++)
                        { 
                            if(wall[settleID[j]].y + wall[settleID[j]].height >= wall[id].y + wall[id].height)
                            { 
                                id = settleID[j];
                            }
                        }
                         this.falltoU(wall[id]);
                         this.re_Settledown(wall,id);
                         this.isStill = true;
                    }
                    break;    
                case 34:                    
                     var t = 0;
                     for(var i = 0;i < wall.length;i++) {
                          if(this.DCollidewall(wall[i],xPre,yPre,xNow,yNow)) {
                              settleID.push(i);
                              t++;                           
                         }
                     }
                     if(t > 0)
                     { 
                        var id = settleID[0];
                       for(var j = 1;j < settleID.length;j++)
                       { 
                           if(wall[settleID[j]].y  >= wall[id].y)
                           { 
                                id = settleID[j];
                           }
                      }
                      this.falltoD(wall[id]);
                      this.re_Settledown(wall,id);
                      this.isStill = true;
                   }
                    break; 
                default:
                    break;
            }                    
    }
    private falltoL(wall:Obstacle)//向左落地
    { 
        this.x = wall.x +wall.width;
     
    }
    private falltoR(wall:Obstacle)//向右落地
    { 
        this.x = wall.x-this.width;
    }
    private falltoU(wall: Obstacle)//向上落地
    { 
        this.y = wall.y +wall.height;
      
    }
    private falltoD(wall: Obstacle)//向下落地
    { 
        this.y = wall.y - this.height;       
    }
    
    private LCollidewall(wall: Obstacle,xPre: number,yPre: number,xNow: number,yNow: number):boolean
    { 
        //这里落地检测在边缘处显得比较生硬，在边缘处如果重叠很小，穿过墙壁运动不好，落在墙上也不合适，
        //只取了一个5像素点的这个值，我也不知道怎么解决。，
        if((xPre >= wall.x + wall.width) && (xNow <= wall.x + wall.width))
        {
            if(((yNow + this.height-5) > wall.y) && (yNow+5  < wall.y + wall.height))
            { 
                return true;
            }
        }
        return false;
    }
    private RCollidewall(wall: Obstacle,xPre: number,yPre: number,xNow: number,yNow: number): boolean
    { 
        
        if((xPre+this.width <= wall.x ) && (xNow +this.width>= wall.x))
        {
            if(((yNow + this.height-5  ) > wall.y) && (yNow+5 <  wall.y + wall.height))
            { 
                return true;
            }
        }
        return false;
    }
    private UCollidewall(wall: Obstacle,xPre: number,yPre: number,xNow: number,yNow: number): boolean
    { 
        
        if((yPre >= wall.y + wall.height) && (yNow <= (wall.y + wall.height)))
        { 
            if(((xNow + this.width-5 ) >  wall.x) && ((xNow+5) <  wall.x + wall.width))
            { 
                return true;
            }
        }
        return false;
    }
    private DCollidewall(wall: Obstacle,xPre: number,yPre: number,xNow: number,yNow: number): boolean
    { 
        if((yPre+this.height <= wall.y ) && (yNow+this.height >= (wall.y)))
        { 
            if(((xNow + this.width-5) >  wall.x) && ((xNow+5) <  wall.x + wall.width))
            { 
                return true;
            }
        }
        return false;
    }
    //检测撞到传送门，不太会用白鹭的碰撞检测，两个圆的比较简单就自己写了
    public hitgate(door: TransGate): boolean {

        var rr = this.width / 2;
        var gr = door.width / 2;
        var rx = this.x + rr;
        var ry = this.y + rr;
        var gx = door.x + gr;
        var gy = door.y + gr;
        var d = Math.pow((rx - gx),2) + Math.pow((ry - gy),2);
        if(d < Math.pow((gr + rr),2))
        { 
            return true;
        }
    
            return false;
    }
    //检测是否碰到记忆球
    public getMemory(ball:MemoryBall[])
    {    

        for(var i = 0;i < ball.length;i++) {
            var rr = this.width / 2;
            var gr = ball[i].width / 2;
            var rx = this.x + rr;
            var ry = this.y + rr;
            var gx = ball[i].x + gr;
            var gy = ball[i].y + gr;
            var d = Math.pow(Math.abs(rx - gx),2) + Math.pow(Math.abs(gy - ry),2);
            if(d < Math.pow((gr + rr),2)) {
                ball[i].set_isAte(true);               
            }
        }
    }
    private re_Settledown(wall:Obstacle[],i:number)
    { 
        //记录落地墙壁的ID，计算相对位置，以提供随墙壁运动的功能
        this.setWallID = i;
        this.wal_to_rolex = this.x - wall[i].x;
        this.wal_to_roley = this.y - wall[i].y;                                                      
    }
    private move_as_wall(wall:Obstacle[]){
        //在随墙壁运动的过程中检测在移动方向是否撞到墙壁，撞到即停止运动
        var preX: number = this.x;
        var preY: number = this.y;
        this.x = wall[this.setWallID].x + this.wal_to_rolex;
        this.y = wall[this.setWallID].y + this.wal_to_roley;
        switch(wall[this.setWallID].movedir)
        { 
            case 0://down
                for(var i = 0;i < wall.length;i++) {
                    if(this.DCollidewall(wall[i],preX,preY,this.x,this.y))
                    { 
                        this.y = wall[i].y - this.height;                        
                    }
                }
                break;
            case 1://up
                for(var i = 0;i < wall.length;i++) {
                     if(this.UCollidewall(wall[i],preX,preY,this.x,this.y))
                    { 
                             this.y = wall[i].y +wall[i].height;
                    }
                }
                break;
            case 2://left
                 for(var i = 0;i < wall.length;i++) {
                    if(this.LCollidewall(wall[i],preX,preY,this.x,this.y))
                    { 
                          this.x = wall[i].x +wall[i].width;
                    }
                }
                break;
            case 3://right
                 for(var i = 0;i < wall.length;i++) {
                     if(this.RCollidewall(wall[i],preX,preY,this.x,this.y))
                     { 
                         this.x = wall[i].x -this.width;
                     }
                }
                break;
            default:
                break;                
        }
    }
}
