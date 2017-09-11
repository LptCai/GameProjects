var StartPanal = (function (_super) {
    __extends(StartPanal, _super);
    function StartPanal() {
        _super.call(this);
        this.vx1 = 0;
        this.vy1 = 0;
        this.vx2 = 0;
        this.vy2 = 0;
        this.t = 0;
        this.init();
    }
    var __egretProto__ = StartPanal.prototype;
    __egretProto__.init = function () {
        this.vx1 = 1;
        this.vy1 = 1;
        this.vx2 = -1;
        this.vy2 = -2;
        //加载开始背景
        this.bg = new egret.Bitmap();
        this.bg.texture = RES.getRes("start_bg_png");
        this.bg.x = 0;
        this.bg.y = 0;
        this.bg.width = DataStruct.stageW;
        this.bg.height = DataStruct.stageH;
        this.addChild(this.bg);
        //加载开始按钮
        this.start_btn = new egret.Bitmap();
        this.start_btn.texture = RES.getRes("start_btn_up_png");
        this.start_btn.x = 170;
        this.start_btn.y = 640;
        this.start_btn.width = 100;
        this.start_btn.height = 100;
        this.addChild(this.start_btn);
        this.start_btn.touchEnabled = true;
        this.start_btn.addEventListener(egret.TouchEvent.TOUCH_BEGIN, this.clickbe, this);
        this.start_btn.addEventListener(egret.TouchEvent.TOUCH_END, this.clickover, this);
    };
    __egretProto__.clickbe = function () {
        this.start_btn.texture = RES.getRes("start_btn_down_png");
    };
    __egretProto__.clickover = function () {
        this.start_btn.texture = RES.getRes("start_btn_up_png");
        DataStruct.stage.dispatchEvent(new egret.Event("prologue")); //发送游戏开始事件      
    };
    return StartPanal;
})(egret.Sprite);
StartPanal.prototype.__class__ = "StartPanal";
//# sourceMappingURL=StartPanal.js.map