var Gmap9 = (function (_super) {
    __extends(Gmap9, _super);
    function Gmap9() {
        _super.call(this);
        this.init();
    }
    var __egretProto__ = Gmap9.prototype;
    __egretProto__.init = function () {
        this.x = 0;
        this.y = 0;
        this.width = 480;
        this.height = 800;
        this.bg = new egret.Bitmap();
        this.bg.texture = RES.getRes(DataStruct.levelmapbg[9]);
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
        this.getui = new egret.Bitmap();
        this.getui.texture = RES.getRes("getui_up_png");
        this.getui.x = 440;
        this.getui.y = 720;
        this.getui.width = 40;
        this.getui.height = 40;
        this.addChild(this.getui);
        this.getui.touchEnabled = true;
        this.getui.addEventListener(egret.TouchEvent.TOUCH_BEGIN, this.getuid, this);
        this.getui.addEventListener(egret.TouchEvent.TOUCH_END, this.getuiu, this);
        this.create_l0();
        this.textArea = new egret.TextField();
        this.textArea.x = 40;
        this.textArea.y = 5;
        this.textArea.width = 400;
        this.textArea.text = "the time went by,and you are here";
        this.textArea.textColor = 0xffffff;
        this.textArea.size = 20;
        this.textArea.background = false;
        this.textArea.fontFamily = "Gabriola";
        this.textArea.textAlign = egret.HorizontalAlign.CENTER;
        this.addChild(this.textArea);
        //设置定时器刷新动画
        this._timer0 = new egret.Timer(30, 0);
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
        for (var i = 0; i < this.walls.length; i++) {
            this.walls[i].move_wall();
        }
        this.role.updateRole_l0(this.walls, this.door, this.balls);
        if (this.role.isOver()) {
            this._timer0.stop();
        }
        //判读是否进入下一关： 
        if (this.role.hitgate(this.door)) {
            DataStruct.levelNow = this.door.getLabel();
            this._timer0.stop();
            DataStruct.stage.dispatchEvent(new egret.Event("nowlevel"));
        }
        for (var i = 0; i < this.balls.length; i++) {
            if (this.balls[i].get_isAte() == true) {
                if (this.balls[i].parent != null) {
                    this.removeChild(this.balls[i]);
                }
            }
        }
    };
    __egretProto__.create_l0 = function () {
        this.role = new Role(0, 0, 0);
        this.addChild(this.role);
        this.walls = [];
        var wall0 = new Obstacle(0, 0, 50, false, 0, 0, 0);
        this.walls.push(wall0);
        for (var i = 0; i < this.walls.length; i++) {
            this.addChild(this.walls[i]);
        }
        this.balls = [];
        var ball0 = new MemoryBall(180, 260, 0, 0);
        this.balls.push(ball0);
        for (var i = 0; i < this.balls.length; i++) {
            this.addChild(this.balls[i]);
        }
        this.door = new TransGate(0, 40, 20);
        this.addChild(this.door);
        this.role.setWallID = 0;
        this.role.wal_to_rolex = this.role.x - this.walls[0].x;
        this.role.wal_to_roley = this.role.x - this.walls[0].y;
    };
    return Gmap9;
})(egret.Sprite);
Gmap9.prototype.__class__ = "Gmap9";
//# sourceMappingURL=Gmap9.js.map