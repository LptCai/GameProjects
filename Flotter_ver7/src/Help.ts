
class Help extends egret.Sprite{
	public constructor() {
        super();
        this.init();
	}
    private quit: egret.Bitmap;
    private bg: egret.Bitmap;
    private init()
    {
        this.bg = new egret.Bitmap();
        this.bg.texture = RES.getRes("help_bg_png");
        this.bg.x = 0;
        this.bg.y = 0;
        this.addChild(this.bg);
        
        //退出按钮
        this.quit = new egret.Bitmap();
        this.quit.texture = RES.getRes("quit_up_png");
        this.quit.x = 210;
        this.quit.y = 640;
        this.addChild(this.quit);
        this.quit.touchEnabled = true;
        this.quit.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.lbtndown,this);
        this.quit.addEventListener(egret.TouchEvent.TOUCH_END,this.lbtnup,this);
    }
    private lbtnup() {
        this.quit.texture = RES.getRes("quit_up_png");
        DataStruct.stage.dispatchEvent(new egret.Event("quit_help"));
    }
    private lbtndown()
    { 
        this.quit.texture = RES.getRes("quit_down_png");
    }
}
