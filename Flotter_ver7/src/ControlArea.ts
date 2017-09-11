
class ControlArea extends egret.Sprite{
	public constructor() {
        super();
        this.init();
	}
    private Area: egret.Bitmap;
    private UpArrow: egret.Bitmap;
    private DownArrow: egret.Bitmap;
    private LeftArrow: egret.Bitmap;
    private RightArrow: egret.Bitmap;
    private init()
    { 
        //感应区域贴图
        this.Area = new egret.Bitmap();
        this.Area.texture = RES.getRes("gtouch1_png");
        this.Area.width = 120;
        this.Area.height = 120;
        this.Area.x = 0;
        this.Area.y = 0;
        this.addChild(this.Area);
        
        //上箭头指示贴图
        this.UpArrow = new egret.Bitmap();
        this.UpArrow.texture = RES.getRes("uparrow_png");
        this.UpArrow.width = 40;
        this.UpArrow.height = 40;
        this.UpArrow.x = 40;
        this.UpArrow.y = 0;
        this.addChild(this.UpArrow);
        this.UpArrow.touchEnabled = true;
        this.UpArrow.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.highlightU,this);
        this.UpArrow.addEventListener(egret.TouchEvent.TOUCH_END,this.normalU,this);
 
        //下箭头指示贴图
        this.DownArrow = new egret.Bitmap();
        this.DownArrow.texture = RES.getRes("downarrow_png");
        this.DownArrow.width = 40;
        this.DownArrow.height = 40;
        this.DownArrow.x = 40;
        this.DownArrow.y = 80;
        this.addChild(this.DownArrow);
        this.DownArrow.touchEnabled = true;
        this.DownArrow.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.highlightD,this);
        this.DownArrow.addEventListener(egret.TouchEvent.TOUCH_END,this.normalD,this);
    
                
        //左箭头指示贴图
        this.LeftArrow= new egret.Bitmap();
        this.LeftArrow.texture = RES.getRes("leftarrow_png");
        this.LeftArrow.width = 40;
        this.LeftArrow.height = 40;
        this.LeftArrow.x = 0;
        this.LeftArrow.y = 40;
        this.addChild(this.LeftArrow);
        this.LeftArrow.touchEnabled = true;
        this.LeftArrow.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.highlightL,this);
        this.LeftArrow.addEventListener(egret.TouchEvent.TOUCH_END,this.normalL,this);
    
                
        
        //右箭头指示贴图
        this.RightArrow = new egret.Bitmap();
        this.RightArrow.texture = RES.getRes("rightarrow_png");
        this.RightArrow.width = 40;
        this.RightArrow.height =40;
        this.RightArrow.x = 80;
        this.RightArrow.y = 40;
        this.addChild(this.RightArrow);
        this.RightArrow.touchEnabled = true;
        this.RightArrow.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.highlightR,this);
        this.RightArrow.addEventListener(egret.TouchEvent.TOUCH_END,this.normalR,this);
   
    }
 
    private highlightU()
    {
        //重力方向设置
        DataStruct.Gdir = 0;
        DataStruct.Gx = 0;
        DataStruct.Gy = DataStruct.Gsize*(-1);
        this.Area.texture = RES.getRes("gtouch0_png");
    }
    private normalU()
    { 
        this.Area.texture = RES.getRes("gtouch1_png");
    }
    private highlightD()
    {
        //重力方向设置
        DataStruct.Gdir = 1;
        DataStruct.Gx = 0;
        DataStruct.Gy = DataStruct.Gsize*1;
        this.Area.texture = RES.getRes("gtouch0_png");
    }
    private normalD()
    {
        this.Area.texture = RES.getRes("gtouch1_png");
    }
    private highlightL()
    {
        //重力方向设置
        DataStruct.Gdir = 2;
        DataStruct.Gx = DataStruct.Gsize*(-1);
        DataStruct.Gy = 0;
        this.Area.texture = RES.getRes("gtouch0_png");
    }
    private normalL()
    { 
        this.Area.texture = RES.getRes("gtouch1_png");
    }
    private highlightR()
    {
        //重力方向设置
        DataStruct.Gdir = 3;
        DataStruct.Gx = DataStruct.Gsize*1;
        DataStruct.Gy = 0;
        this.Area.texture = RES.getRes("gtouch0_png");
    }
    private normalR()
    { 
        this.Area.texture = RES.getRes("gtouch1_png");
    }  
}
