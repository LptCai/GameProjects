var Gmap11 = (function (_super) {
    __extends(Gmap11, _super);
    function Gmap11() {
        _super.call(this);
        this.init();
    }
    var __egretProto__ = Gmap11.prototype;
    __egretProto__.init = function () {
        this.x = 0;
        this.y = 0;
        this.width = 480;
        this.height = 800;
        this.bg = new egret.Bitmap();
        this.bg.texture = RES.getRes(DataStruct.levelmapbg[11]);
        this.bg.x = 0;
        this.bg.y = 0;
        this.bg.width = DataStruct.stageW;
        this.bg.height = DataStruct.stageH;
        this.addChild(this.bg);
        //感应区域加载：
        this.Gcontrol = new ControlArea();
        this.Gcontrol.x = 180;
        this.Gcontrol.y = 680;
        this.Gcontrol.width = 120;
        this.Gcontrol.height = 120;
        this.addChild(this.Gcontrol);
        //音乐控件
        this.music = new Music();
        this.addChild(this.music);
        //UI调用
        /*this.getui = new egret.Bitmap();
        this.getui.texture = RES.getRes("getui_up_png");
        this.getui.x = 440;
        this.getui.y = 720;
        this.getui.width = 40;
        this.getui.height = 40;
        this.addChild(this.getui);
        this.getui.touchEnabled = true;
        this.getui.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.getuid,this);
        this.getui.addEventListener(egret.TouchEvent.TOUCH_END,this.getuiu,this);*/
        this.create_l0();
        this.textArea = new egret.TextField();
        this.textArea.x = 40;
        this.textArea.y = 10;
        this.textArea.width = 400;
        this.textArea.text = "未完待续";
        this.textArea.textColor = 0xffffff;
        this.textArea.size = 15;
        this.textArea.background = false;
        this.textArea.fontFamily = "华文楷体";
        this.textArea.textAlign = egret.HorizontalAlign.CENTER;
        this.addChild(this.textArea);
        //设置定时器刷新动画
        this._timer0 = new egret.Timer(5000, 1);
        this._timer0.addEventListener(egret.TimerEvent.TIMER, this.update, this);
        this._timer0.start();
    };
    __egretProto__.getuid = function () {
        this.getui.texture = RES.getRes("getui_down_png");
        this._timer0.stop();
        DataStruct.stage.dispatchEvent(new egret.Event("gameover"));
    };
    __egretProto__.getuiu = function () {
        this.getui.texture = RES.getRes("getui_up_png");
    };
    __egretProto__.update = function () {
        DataStruct.stage.dispatchEvent(new egret.Event("epilogue"));
    };
    __egretProto__.create_l0 = function () {
        this.role = new Role(230, 510, 0);
        this.addChild(this.role);
        this.walls = [];
        var wall0 = new Obstacle(0, 190, 560, false, 0, 0, 0);
        this.walls.push(wall0);
        for (var i = 0; i < this.walls.length; i++) {
            this.addChild(this.walls[i]);
        }
        this.role.setWallID = 0;
        this.role.wal_to_rolex = this.role.x - this.walls[0].x;
        this.role.wal_to_roley = this.role.x - this.walls[0].y;
    };
    return Gmap11;
})(egret.Sprite);
Gmap11.prototype.__class__ = "Gmap11";
//# sourceMappingURL=Gmap11.js.map