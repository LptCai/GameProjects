var MemoryBall = (function (_super) {
    __extends(MemoryBall, _super);
    function MemoryBall(x, y, tlabel, plabel) {
        _super.call(this);
        this.flagball = 0;
        this.isAte = false;
        this.init(x, y, tlabel, plabel);
    }
    var __egretProto__ = MemoryBall.prototype;
    __egretProto__.init = function (x, y, label, plabel) {
        this.Piclabel = plabel;
        this.textlabel = label;
        this.flagball = 0;
        this.isAte = false;
        this.ball = new egret.Bitmap();
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
        this._timer1 = new egret.Timer(500, 0);
        this._timer1.addEventListener(egret.TimerEvent.TIMER, this.updateball, this);
        this._timer1.start();
    };
    __egretProto__.getpiclabel = function () {
        return this.Piclabel;
    };
    __egretProto__.updateball = function () {
        if (this.flagball == 0) {
            this.ball.texture = RES.getRes(DataStruct.balls_1[this.Piclabel]);
            this.flagball = 1;
        }
        else {
            this.ball.texture = RES.getRes(DataStruct.balls_0[this.Piclabel]);
            this.flagball = 0;
        }
    };
    __egretProto__.get_isAte = function () {
        return this.isAte;
    };
    __egretProto__.set_isAte = function (val) {
        this.isAte = val;
    };
    return MemoryBall;
})(egret.Sprite);
MemoryBall.prototype.__class__ = "MemoryBall";
//# sourceMappingURL=MemoryBall.js.map