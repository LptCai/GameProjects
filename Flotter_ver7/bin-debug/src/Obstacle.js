var Obstacle = (function (_super) {
    __extends(Obstacle, _super);
    function Obstacle(type, x, y, move, dir, movepace_d, movepace_u) {
        _super.call(this);
        this.init(type, x, y, move, dir, movepace_d, movepace_u);
    }
    var __egretProto__ = Obstacle.prototype;
    __egretProto__.init = function (type, x, y, move, dir, movepace_d, movepace_u) {
        this.x = x;
        this.y = y;
        this.movepace_d = movepace_d;
        this.movepace_u = movepace_u;
        this.canmove = move;
        this.movedir = dir;
        this.wall = new egret.Bitmap();
        if (type == 0) {
            this.wall.texture = RES.getRes("wall0_png");
            this.wall.x = 0;
            this.wall.y = 0;
            this.wall.width = 120;
            this.wall.height = 30;
            this.width = 120;
            this.height = 30;
        }
        else if (type == 1) {
            this.wall = new egret.Bitmap();
            this.wall.texture = RES.getRes("wall1_png");
            this.wall.x = 0;
            this.wall.y = 0;
            this.wall.width = 30;
            this.wall.height = 120;
            this.width = 30;
            this.height = 120;
        }
        this.addChild(this.wall);
    };
    __egretProto__.move_wall = function () {
        if (this.canmove == true) {
            switch (this.movedir) {
                case 0:
                    this.y = DataStruct.movespeed + this.y;
                    if (this.y + this.height > this.movepace_u) {
                        this.movedir = 1;
                    }
                    break;
                case 1:
                    this.y = -DataStruct.movespeed + this.y;
                    if (this.y < this.movepace_d) {
                        this.movedir = 0;
                    }
                    break;
                case 2:
                    this.x = -DataStruct.movespeed + this.x;
                    if (this.x + this.width < this.movepace_d) {
                        this.movedir = 3;
                    }
                    break;
                case 3:
                    this.x = DataStruct.movespeed + this.x;
                    if (this.x > this.movepace_u) {
                        this.movedir = 2;
                    }
                    break;
            }
        }
    };
    return Obstacle;
})(egret.Sprite);
Obstacle.prototype.__class__ = "Obstacle";
//# sourceMappingURL=Obstacle.js.map