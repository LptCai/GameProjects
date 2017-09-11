
class OverPanal extends egret.Sprite{
    public constructor() {
        super();
        this.init();
    }
    private bg:egret.Bitmap;
    private again_btn: egret.Bitmap;
    private tomenu: egret.Bitmap;
    private endtime: egret.Bitmap;
    private init()
    {
        //绘制背景
        this.bg = new egret.Bitmap();
        this.bg.texture = RES.getRes("overbg_png");
        this.bg.x = 0;
        this.bg.y = 0;
        this.bg.width = DataStruct.stageW;
        this.bg.height = DataStruct.stageH;
        this.addChild(this.bg);
        
        //绘制当前探索度的时钟指示
        this.endtime = new egret.Bitmap();
        this.endtime.texture = RES.getRes(DataStruct.overclock[DataStruct.levelNow]);
        this.endtime.x = 90;
        this.endtime.y = 200;
        this.addChild(this.endtime);
                
        //绘制再来一次按钮
        this.again_btn = new egret.Bitmap();
        this.again_btn.texture = RES.getRes("again_btn_up_png");
        this.again_btn.x = 30;
        this.again_btn.y = 500;
        this.again_btn.width = 100;
        this.again_btn.height = 100;
        this.addChild(this.again_btn);
        this.again_btn.touchEnabled = true;
        this.again_btn.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.againdown,this);
        this.again_btn.addEventListener(egret.TouchEvent.TOUCH_END,this.againup,this);
                
                
        //绘制弹出UI界面按钮
        this.tomenu = new egret.Bitmap();
        this.tomenu.texture = RES.getRes("menu_btn_up_png");
        this.tomenu.x = 360;
        this.tomenu.y = 500;
        this.tomenu.width = 100;
        this.tomenu.height = 100;
        this.addChild(this.tomenu);
        this.tomenu.touchEnabled = true;
        this.tomenu.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.menudown,this);
        this.tomenu.addEventListener(egret.TouchEvent.TOUCH_END,this.menuup,this);
                
        }
        private againdown()
        {
            this.again_btn.texture = RES.getRes("again_btn_down_png");
            
            
        }
        private againup()
        { 
            this.again_btn.texture = RES.getRes("again_btn_up_png");
           //派发开始本关卡事件            
            DataStruct.stage.dispatchEvent(new egret.Event("nowlevel"));
            console.log("newgame");
        }
        private menudown()
        {
            this.tomenu.texture = RES.getRes("menu_btn_down_png");

        }
        private menuup()
        {
            this.tomenu.texture = RES.getRes("menu_btn_up_png");
           //派发调用UI事件
            DataStruct.stage.dispatchEvent(new egret.Event("tomenu"));
            console.log("tomenu");
        }
            
        }
        