
class MemoryBall extends egret.Sprite{
	public constructor(x:number,y:number,tlabel:number,plabel:number) {
        super();
        this.init(x,y,tlabel,plabel);
	}
    public ball: egret.Bitmap;
    public textlabel: number;//文字信息，对应于DataStruct中的文字信息字符串
    private Piclabel: number;//图片标签，根据其加载图片，对应data中的ball图片数组
    private _timer1:egret.Timer;
    private flagball: number=0;
    private isAte: boolean=false;
    private init(x:number,y:number,label:number,plabel:number)
    { 
        this.Piclabel = plabel;
        this.textlabel = label;
        this.flagball = 0;
        this.isAte = false;
        
        this.ball=new egret.Bitmap()
        this.ball.texture = RES.getRes(DataStruct.balls_0[plabel]);
        this.ball.x = 0;
        this.ball.y = 0;
        this.ball.width = 40;
        this.ball.height = 40;
        
        this.addChild(this.ball);
        this.x = x;
        this.y = y;
        this.width = 40;
        this.height = 40;
        
        this._timer1 = new egret.Timer(500,0);
        this._timer1.addEventListener(egret.TimerEvent.TIMER,this.updateball,this);
        this._timer1.start();
    }
    public getpiclabel():number
    { 
        return this.Piclabel;
    }
    private updateball()
    { 
        if(this.flagball == 0) {
            this.ball.texture = RES.getRes(DataStruct.balls_1[this.Piclabel]);
            this.flagball = 1;
        } else { 
            this.ball.texture = RES.getRes(DataStruct.balls_0[this.Piclabel]);
            this.flagball = 0;
        }
    }
    public get_isAte():boolean
    { 
        return this.isAte;
    }
    public set_isAte(val:boolean)
    {
        this.isAte = val;
    }
	
}
