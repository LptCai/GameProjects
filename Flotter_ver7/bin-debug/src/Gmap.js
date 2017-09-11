//教学关卡
var Gmap = (function (_super) {
    __extends(Gmap, _super);
    function Gmap() {
        _super.call(this);
        this.ateballnum = 0; //记录记忆球是否完全被吃掉
        this.init();
    }
    var __egretProto__ = Gmap.prototype;
    __egretProto__.init = function () {
        this.x = 0;
        this.y = 0;
        this.width = 480;
        this.height = 800;
        this.bg = new egret.Bitmap();
        this.bg.texture = RES.getRes(DataStruct.levelmapbg[0]);
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
        //绘制本关卡地图
        this.create_l0();
        //头顶信息区文字输出
        this.textArea = new egret.TextField();
        this.textArea.x = 40;
        this.textArea.y = 15;
        this.textArea.width = 400;
        this.textArea.text = "探索·点击下方的按钮探索你所在的世界";
        this.textArea.textColor = 0xffffff;
        this.textArea.size = 15;
        this.textArea.background = false;
        this.textArea.fontFamily = "华文楷体";
        this.textArea.textAlign = egret.HorizontalAlign.CENTER;
        this.addChild(this.textArea);
        //设置定时器刷新动画
        this._timer0 = new egret.Timer(30, 0);
        this._timer0.addEventListener(egret.TimerEvent.TIMER, this.update, this);
        this._timer0.start();
    };
    //ui按钮的控制
    __egretProto__.getuid = function () {
        this.getui.texture = RES.getRes("getui_down_png");
        this._timer0.stop();
        DataStruct.stage.dispatchEvent(new egret.Event("gameover"));
    };
    __egretProto__.getuiu = function () {
        this.getui.texture = RES.getRes("getui_up_png");
    };
    //地图画面刷新
    __egretProto__.update = function () {
        for (var i = 0; i < this.walls.length; i++) {
            this.walls[i].move_wall();
        }
        this.role.updateRole_l0(this.walls, this.door, this.balls);
        //判断游戏是否结束
        if (this.role.isOver()) {
            this._timer0.stop();
        }
        //判读是否进入下一关：
        if (this.door != null) {
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
                    this.textArea.text = DataStruct.memorytex[this.balls[i].textlabel];
                    this.removeChild(this.balls[i]);
                    this.ateballnum++;
                }
            }
        }
        //更新文字信息。动态控制墙壁等
        if (this.ateballnum == 3) {
            this.textArea.text = "上下左右的点击，改变了重力，这种掌控何尝不是一种失重";
            DataStruct.Gdir = 1;
            DataStruct.Gx = 0;
            DataStruct.Gy = DataStruct.Gsize * 1;
            this._timer1 = new egret.Timer(30, 0);
            this._timer1.addEventListener(egret.TimerEvent.TIMER, this.wallchange, this);
            this._timer1.start();
            this.ateballnum = 0;
            //上方生成新墙壁：
            var wall8 = new Obstacle(0, -120, 100, true, 3, -120, 600); //可移动的墙壁
            this.walls.push(wall8);
            this.addChild(this.walls[8]);
            this.addChild(this.door);
        }
    };
    __egretProto__.create_l0 = function () {
        //绘制障碍物
        this.role = new Role(200, 420, 0);
        this.addChild(this.role);
        this.walls = [];
        var wall0 = new Obstacle(0, 120, 200, false, 0, 0, 0); //横上左
        var wall1 = new Obstacle(0, 240, 200, false, 0, 0, 0); //横上右
        var wall2 = new Obstacle(0, 120, 470, false, 0, 0, 0); //横下左
        var wall3 = new Obstacle(0, 240, 470, false, 0, 0, 0); //横下右
        var wall4 = new Obstacle(1, 90, 230, false, 0, 0, 0); //竖左上
        var wall5 = new Obstacle(1, 90, 350, false, 0, 0, 0); //竖左下
        var wall6 = new Obstacle(1, 360, 230, false, 0, 0, 0); //竖右上
        var wall7 = new Obstacle(1, 360, 350, false, 0, 0, 0); //竖右下
        this.walls.push(wall0);
        this.walls.push(wall1);
        this.walls.push(wall2);
        this.walls.push(wall3);
        this.walls.push(wall4);
        this.walls.push(wall5);
        this.walls.push(wall6);
        this.walls.push(wall7);
        for (var i = 0; i < this.walls.length; i++) {
            this.addChild(this.walls[i]);
        }
        //绘制记忆球
        this.balls = [];
        var ball0 = new MemoryBall(320, 280, 0, 0);
        var ball1 = new MemoryBall(180, 230, 0, 0);
        var ball2 = new MemoryBall(120, 300, 0, 0);
        this.balls.push(ball0);
        this.balls.push(ball1);
        this.balls.push(ball2);
        for (var i = 0; i < this.balls.length; i++) {
            this.addChild(this.balls[i]);
        }
        //绘制传送门
        this.door = new TransGate(1, 350, 560);
        //角色与此时落地墙壁的相对位置记录
        this.role.setWallID = 2;
        this.role.wal_to_rolex = this.role.x - this.walls[2].x;
        this.role.wal_to_roley = this.role.y - this.walls[2].y;
    };
    __egretProto__.wallchange = function () {
        this.walls[0].x -= 2;
        this.walls[0].movedir = 2;
        this.walls[1].x += 2;
        this.walls[1].movedir = 3;
        if (this.walls[8].x >= 240) {
            this.textArea.text = "捕捉每一个可落的点，寻找出口";
        }
    };
    return Gmap;
})(egret.Sprite);
Gmap.prototype.__class__ = "Gmap";
//# sourceMappingURL=Gmap.js.map