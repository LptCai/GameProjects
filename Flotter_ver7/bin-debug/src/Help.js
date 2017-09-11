var Help = (function (_super) {
    __extends(Help, _super);
    function Help() {
        _super.call(this);
        this.init();
    }
    var __egretProto__ = Help.prototype;
    __egretProto__.init = function () {
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
        this.quit.addEventListener(egret.TouchEvent.TOUCH_BEGIN, this.lbtndown, this);
        this.quit.addEventListener(egret.TouchEvent.TOUCH_END, this.lbtnup, this);
    };
    __egretProto__.lbtnup = function () {
        this.quit.texture = RES.getRes("quit_up_png");
        DataStruct.stage.dispatchEvent(new egret.Event("quit_help"));
    };
    __egretProto__.lbtndown = function () {
        this.quit.texture = RES.getRes("quit_down_png");
    };
    return Help;
})(egret.Sprite);
Help.prototype.__class__ = "Help";
//# sourceMappingURL=Help.js.map