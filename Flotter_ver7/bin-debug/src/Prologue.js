var Prologue = (function (_super) {
    __extends(Prologue, _super);
    function Prologue() {
        _super.call(this);
        this.init();
    }
    var __egretProto__ = Prologue.prototype;
    __egretProto__.init = function () {
        this.bg = new egret.Bitmap();
        this.bg.texture = RES.getRes("pro_bg_png");
        this.bg.x = 0;
        this.bg.y = 0;
        this.bg.width = DataStruct.stageW;
        this.bg.height = DataStruct.stageH;
        this.addChild(this.bg);
        this._timer1 = new egret.Timer(5000, 1);
        this._timer1.addEventListener(egret.TimerEvent.TIMER, this.start, this);
        this._timer1.start();
    };
    __egretProto__.start = function () {
        DataStruct.stage.dispatchEvent(new egret.Event("startgame"));
        this._timer1.stop();
    };
    return Prologue;
})(egret.Sprite);
Prologue.prototype.__class__ = "Prologue";
//# sourceMappingURL=Prologue.js.map