//旅程·一个人的肆意美好
var Gmap3 = (function (_super) {
    __extends(Gmap3, _super);
    function Gmap3() {
        _super.call(this);
        this.memnum = 0;
        this.init();
    }
    var __egretProto__ = Gmap3.prototype;
    __egretProto__.init = function () {
        this.x = 0;
        this.y = 0;
        this.width = 480;
        this.height = 800;
        this.bg = new egret.Bitmap();
        this.bg.texture = RES.getRes(DataStruct.levelmapbg[3]);
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
        this.textArea.y = 10;
        this.textArea.width = 400;
        this.textArea.text = "旅程·一个人的肆意美好";
        this.textArea.textColor = 0xffffff;
        this.textArea.size = 15;
        this.textArea.background = false;
        this.textArea.fontFamily = "华文楷体";
        this.textArea.textAlign = egret.HorizontalAlign.CENTER;
        this.addChild(this.textArea);
        //
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
        if (this.door != null && this.door.parent != null) {
            if (this.role.hitgate(this.door)) {
                DataStruct.levelNow = this.door.getLabel();
                DataStruct.levelclock[DataStruct.levelNow] = true; //若通关此关卡解锁
                this._timer0.stop();
                DataStruct.stage.dispatchEvent(new egret.Event("nowlevel"));
            }
        }
        for (var i = 0; i < this.balls.length; i++) {
            if (this.balls[i].get_isAte() == true) {
                if (this.balls[i].parent != null) {
                    this.removeChild(this.balls[i]);
                    this.memnum++;
                }
            }
        }
        if (this.memnum == 4) {
            this.addChild(this.door);
        }
    };
    __egretProto__.create_l0 = function () {
        this.role = new Role(420, 550, 0);
        this.addChild(this.role);
        this.walls = [];
        var wall0 = new Obstacle(0, 360, 600, false, 0, 0, 0); //original settle
        var wall1 = new Obstacle(1, 200, 240, false, 0, 0, 0); //the vertical at middle
        var wall2 = new Obstacle(0, 0, 400, true, 3, -120, 600);
        var wall4 = new Obstacle(0, 400, 140, true, 2, -120, 600);
        var wall5 = new Obstacle(0, 100, 50, false, 0, 0, 0); //the one  on the top
        var wall6 = new Obstacle(0, 240, 500, false, 0, 0, 0); // the bottom one
        this.walls.push(wall0);
        this.walls.push(wall1);
        this.walls.push(wall2);
        this.walls.push(wall4);
        this.walls.push(wall5);
        this.walls.push(wall6);
        for (var i = 0; i < this.walls.length; i++) {
            this.addChild(this.walls[i]);
        }
        this.balls = [];
        var ball0 = new MemoryBall(230, 240, 9, 1); //vertical right
        var ball1 = new MemoryBall(250, 460, 10, 2); //
        var ball3 = new MemoryBall(160, 290, 11, 1); //verticalleft
        var ball4 = new MemoryBall(120, 80, 12, 0);
        this.balls.push(ball0);
        this.balls.push(ball1);
        this.balls.push(ball3);
        this.balls.push(ball4);
        for (var i = 0; i < this.balls.length; i++) {
            this.addChild(this.balls[i]);
        }
        this.door = new TransGate(4, 400, 500);
        this.role.setWallID = 0;
        this.role.wal_to_rolex = this.role.x - this.walls[0].x;
        this.role.wal_to_roley = this.role.y - this.walls[0].y;
    };
    return Gmap3;
})(egret.Sprite);
Gmap3.prototype.__class__ = "Gmap3";
//# sourceMappingURL=Gmap3.js.map