class Gesture
{
    public constructor(NowState:number) {
        this.init(NowState);
    }
    private _nowtype: number;//当前手势识别控制模式0：游戏进程重力模式1：选关模式,由于操作模式效果不好舍弃
    private init(val:number)
    { 
        this._nowtype = val;
    }
    private _layer:egret.Shape;
    public addEvent(layer:egret.Shape)//捕捉鼠标事件
    {
        this._layer = layer;
        
        egret.MainContext.instance.stage.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.mouseDown,this);
        egret.MainContext.instance.stage.addEventListener(egret.TouchEvent.TOUCH_END,this.mouseUp,this);
        egret.MainContext.instance.stage.addEventListener(egret.TouchEvent.TOUCH_MOVE,this.mouseMove,this);
        
        }
        
        private _mouseDatas:egret.Point[];//鼠标移过的点的记录数组
        private _currentPoint:egret.Point;//当前鼠标按下的点
        private mouseDown(evt:egret.TouchEvent)
        {
            this._layer.graphics.clear();
            this._mouseDatas = [];
            var p:egret.Point = new egret.Point(evt.stageX,evt.stageY);
            this._mouseDatas.push(p);
            this._currentPoint = p;
        }
        private mouseMove(evt:egret.TouchEvent)
        {
            var p:egret.Point = new egret.Point(evt.stageX,evt.stageY);
            this._mouseDatas.push(p);
            
            this._layer.graphics.lineStyle(1,0) ;
            this._layer.graphics.moveTo(this._currentPoint.x,this._currentPoint.y);
            this._layer.graphics.lineTo(p.x,p.y);
            this._layer.graphics.endFill();
            this._currentPoint = p;
        }
        private mouseUp(evt:egret.TouchEvent)
        {
            var p:egret.Point = new egret.Point(evt.stageX,evt.stageY);
            this._mouseDatas.push(p);            
            this._layer.graphics.clear();           
            this.motion();
        }
        
        private motion()
        {
            var _arr:egret.Point[] = [];
            var currentIndex:number = 0;
            var len:number = this._mouseDatas.length;
            _arr.push(this._mouseDatas[currentIndex]);
            for(var i:number=0; i<len; i++)
            {
                if( egret.Point.distance(this._mouseDatas[currentIndex], this._mouseDatas[i])>20 )//若记录大于30个像素，则做相对位置的计算
                {
                    currentIndex = i;
                    _arr.push(this._mouseDatas[currentIndex]);
                }
            }
            
            this._mouseDatas = _arr;//将鼠标坐标记录点数组设置为有效点坐标数组
            this.parseDirection();
        }
        
        private _dirsArr:number[];
        private parseDirection()
        {
            
            this._dirsArr = [];
            var len:number = this._mouseDatas.length;
            for(var i:number=0; i<len; i++)
            {
                if( this._mouseDatas[i+1])
                {
                    var p1:egret.Point = this._mouseDatas[i];
                    var p2:egret.Point = this._mouseDatas[i+1];
                    var a:number = p1.y - p2.y;
                    var b:number = egret.Point.distance(p1,p2);
                    var rad:number = Math.asin( a/b );
                    var ang:number = rad * 57.2957800; // rad * 180/Math.PI 直接求常量，优化
                    var quad:number = this.quadrant(p1,p2);
                    var dir:number = this.getDirByAngQuad(ang, quad);
                    this._dirsArr.push(dir);//记录有效点坐标的角度变化情况……
                }
            }
            //根据初始化的值判断当前手势识别模式
            if(this._nowtype == 0) {
                var gdir = this.getDir(this._dirsArr);
                this.setG(gdir);
            } else if(this._nowtype == 1)
            { 
                var d = this.getDir(this._dirsArr);
                this.getLevel(d);
            }
        }  
                        
        //获得当前选关前进或后退：
        private getLevel(val:number)
        {
            if(val == 2) { 
                //关卡应该加：
                console.log("guanqiajia");
                DataStruct.stage.dispatchEvent(new egret.Event("level_increace"));
            } else if(val == 3)
            { 
                //关卡应该减
                console.log("guanqiajian");
                DataStruct.stage.dispatchEvent(new egret.Event("level_deline"));
            }
        }
        //得到当前方向：
        private getDir(dir:number[]):number
        { 
            var _dir: number=DataStruct.Gdir;
            var len = dir.length;
            var up: number=0;
            var down: number=0;
            var left: number=0;
            var right: number=0;
            for(var i: number = 0;i < len;i++) {
                if(dir[i] == 0) { up++;}
                if(dir[i] == 1) { down++;}
                if(dir[i] == 2) { left++;}
                if(dir[i] == 3) { right++;}
            }
            if(len >= 2) {
                if(up >= len * 2 / 3) {
                    _dir = 0;
                } else if(down >= len * 2 / 3) {
                    _dir = 1;
                } else if(left >= len * 2 / 3) {
                    _dir = 2;
                } else if(right >= len * 2 / 3) {
                    _dir = 3;
                }
            }
            return _dir;
        }
        //重力方向大小的改变
        private setG(dir:number)
        { 
            switch(dir)
            { 
                case 0:
                DataStruct.Gdir = 0;
                DataStruct.Gx = 0;
                DataStruct.Gy = DataStruct.Gsize*(-1);
                console.log("shang");
                break;
                case 1:
                DataStruct.Gdir = 1;
                DataStruct.Gx = 0;
                DataStruct.Gy = DataStruct.Gsize*1;
                console.log("xia");
                break;
                case 2:
                DataStruct.Gdir = 2;
                DataStruct.Gx = DataStruct.Gsize*(-1);
                DataStruct.Gy = 0;
                console.log("zuo");
                break;
                case 3:
                DataStruct.Gdir = 3;
                DataStruct.Gx = DataStruct.Gsize*1;
                DataStruct.Gy = 0;
                console.log("you");
                break;
            }
        }
        /*
        根据所在象限与角度计算出方向编号。0上1下2左3右
        方向编号，以第一象限45度为基础，按照顺时针方向，将圆等分为4份。
        */
        private getDirByAngQuad(ang:number,quad:number):number
        {
            switch(quad)
            {
                case 1:
                if( ang<=45 && ang>= 0 )
                {
                    return 3;
                }
                else if( ang<= 90 && ang> 45 )
                {
                    return 0;
                }
                case 2:
                if( ang< 45 && ang>=0 )
                {
                    return 2;
                }
                else if( ang<= 90 && ang> 45 )
                {
                    return 0;
                }
                break;
                case 3:
                if( ang<= -45 && ang> -90 )
                {
                    return 1;
                }
                else if( ang<=0 && ang> -45 )
                {
                    return 2;
                }
                break;
                case 4:
                if( ang<=-45 && ang>= -90 )
                {
                    return 1;
                }
                else if( ang<=0 && ang>-45)
                {
                    return 3;
                }
                
                break;
            }
        }
        
        /*
        计算两点关系所形成的象限
        以P1 作为坐标原点，P2为设定点，判断P2相对于P1时所在象限
        */
        private quadrant(p1:egret.Point,p2:egret.Point):number
        {
            if(p2.x>=p1.x)
            {
                if( p2.y <= p1.y )
                {
                    return 1;
                }
                else
                {
                    return 4;
                }
            }
            else
            {
                if( p2.y <= p1.y )
                {
                    return 2;
                }
                else
                {
                    return 3;
                }
            }
        }  
    }