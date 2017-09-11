var TransGate = (function (_super) {
    __extends(TransGate, _super);
    function TransGate(label, x, y) {
        {
            _super.call(this);
            this.init(label, x, y);
        }
    }
    var __egretProto__ = TransGate.prototype;
    __egretProto__.init = function (label, x, y) {
        this.label = label;
        this.gate = new egret.Bitmap();
        this.gate.texture = RES.getRes(DataStruct.gates[this.label]);
        this.gate.x = 0;
        this.gate.y = 0;
        this.gate.width = 100;
        this.gate.height = 100;
        this.addChild(this.gate);
        this.x = x;
        this.y = y;
        this.width = this.gate.width;
        this.height = this.gate.height;
    };
    __egretProto__.getLabel = function () {
        return this.label;
    };
    return TransGate;
})(egret.Sprite);
TransGate.prototype.__class__ = "TransGate";
//# sourceMappingURL=TransGate.js.map