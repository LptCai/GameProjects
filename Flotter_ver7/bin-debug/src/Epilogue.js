//游戏终章全部通关后出现，由于关卡未完结，让它自动出现了
var Epilogue = (function (_super) {
    __extends(Epilogue, _super);
    function Epilogue() {
        _super.call(this);
        this.init();
    }
    var __egretProto__ = Epilogue.prototype;
    __egretProto__.init = function () {
        this.bg = new egret.Bitmap();
        this.bg.texture = RES.getRes("epibg_png");
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
        DataStruct.stage.dispatchEvent(new egret.Event("gameover"));
        this._timer1.stop();
    };
    return Epilogue;
})(egret.Sprite);
Epilogue.prototype.__class__ = "Epilogue";
//# sourceMappingURL=Epilogue.js.map