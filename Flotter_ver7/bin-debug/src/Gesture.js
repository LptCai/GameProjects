var Gesture = (function () {
    function Gesture(NowState) {
        this.init(NowState);
    }
    var __egretProto__ = Gesture.prototype;
    __egretProto__.init = function (val) {
        this._nowtype = val;
    };
    __egretProto__.addEvent = function (layer) {
        this._layer = layer;
        egret.MainContext.instance.stage.addEventListener(egret.TouchEvent.TOUCH_BEGIN, this.mouseDown, this);
        egret.MainContext.instance.stage.addEventListener(egret.TouchEvent.TOUCH_END, this.mouseUp, this);
        egret.MainContext.instance.stage.addEventListener(egret.TouchEvent.TOUCH_MOVE, this.mouseMove, this);
    };
    __egretProto__.mouseDown = function (evt) {
        this._layer.graphics.clear();
        this._mouseDatas = [];
        var p = new egret.Point(evt.stageX, evt.stageY);
        this._mouseDatas.push(p);
        this._currentPoint = p;
    };
    __egretProto__.mouseMove = function (evt) {
        var p = new egret.Point(evt.stageX, evt.stageY);
        this._mouseDatas.push(p);
        this._layer.graphics.lineStyle(1, 0);
        this._layer.graphics.moveTo(this._currentPoint.x, this._currentPoint.y);
        this._layer.graphics.lineTo(p.x, p.y);
        this._layer.graphics.endFill();
        this._currentPoint = p;
    };
    __egretProto__.mouseUp = function (evt) {
        var p = new egret.Point(evt.stageX, evt.stageY);
        this._mouseDatas.push(p);
        this._layer.graphics.clear();
        this.motion();
    };
    __egretProto__.motion = function () {
        var _arr = [];
        var currentIndex = 0;
        var len = this._mouseDatas.length;
        _arr.push(this._mouseDatas[currentIndex]);
        for (var i = 0; i < len; i++) {
            if (egret.Point.distance(this._mouseDatas[currentIndex], this._mouseDatas[i]) > 20) {
                currentIndex = i;
                _arr.push(this._mouseDatas[currentIndex]);
            }
        }
        this._mouseDatas = _arr; //将鼠标坐标记录点数组设置为有效点坐标数组
        this.parseDirection();
    };
    __egretProto__.parseDirection = function () {
        this._dirsArr = [];
        var len = this._mouseDatas.length;
        for (var i = 0; i < len; i++) {
            if (this._mouseDatas[i + 1]) {
                var p1 = this._mouseDatas[i];
                var p2 = this._mouseDatas[i + 1];
                var a = p1.y - p2.y;
                var b = egret.Point.distance(p1, p2);
                var rad = Math.asin(a / b);
                var ang = rad * 57.2957800; // rad * 180/Math.PI 直接求常量，优化
                var quad = this.quadrant(p1, p2);
                var dir = this.getDirByAngQuad(ang, quad);
                this._dirsArr.push(dir); //记录有效点坐标的角度变化情况……
            }
        }
        //根据初始化的值判断当前手势识别模式
        if (this._nowtype == 0) {
            var gdir = this.getDir(this._dirsArr);
            this.setG(gdir);
        }
        else if (this._nowtype == 1) {
            var d = this.getDir(this._dirsArr);
            this.getLevel(d);
        }
    };
    //获得当前选关前进或后退：
    __egretProto__.getLevel = function (val) {
        if (val == 2) {
            //关卡应该加：
            console.log("guanqiajia");
            DataStruct.stage.dispatchEvent(new egret.Event("level_increace"));
        }
        else if (val == 3) {
            //关卡应该减
            console.log("guanqiajian");
            DataStruct.stage.dispatchEvent(new egret.Event("level_deline"));
        }
    };
    //得到当前方向：
    __egretProto__.getDir = function (dir) {
        var _dir = DataStruct.Gdir;
        var len = dir.length;
        var up = 0;
        var down = 0;
        var left = 0;
        var right = 0;
        for (var i = 0; i < len; i++) {
            if (dir[i] == 0) {
                up++;
            }
            if (dir[i] == 1) {
                down++;
            }
            if (dir[i] == 2) {
                left++;
            }
            if (dir[i] == 3) {
                right++;
            }
        }
        if (len >= 2) {
            if (up >= len * 2 / 3) {
                _dir = 0;
            }
            else if (down >= len * 2 / 3) {
                _dir = 1;
            }
            else if (left >= len * 2 / 3) {
                _dir = 2;
            }
            else if (right >= len * 2 / 3) {
                _dir = 3;
            }
        }
        return _dir;
    };
    //重力方向大小的改变
    __egretProto__.setG = function (dir) {
        switch (dir) {
            case 0:
                DataStruct.Gdir = 0;
                DataStruct.Gx = 0;
                DataStruct.Gy = DataStruct.Gsize * (-1);
                console.log("shang");
                break;
            case 1:
                DataStruct.Gdir = 1;
                DataStruct.Gx = 0;
                DataStruct.Gy = DataStruct.Gsize * 1;
                console.log("xia");
                break;
            case 2:
                DataStruct.Gdir = 2;
                DataStruct.Gx = DataStruct.Gsize * (-1);
                DataStruct.Gy = 0;
                console.log("zuo");
                break;
            case 3:
                DataStruct.Gdir = 3;
                DataStruct.Gx = DataStruct.Gsize * 1;
                DataStruct.Gy = 0;
                console.log("you");
                break;
        }
    };
    /*
    根据所在象限与角度计算出方向编号。0上1下2左3右
    方向编号，以第一象限45度为基础，按照顺时针方向，将圆等分为4份。
    */
    __egretProto__.getDirByAngQuad = function (ang, quad) {
        switch (quad) {
            case 1:
                if (ang <= 45 && ang >= 0) {
                    return 3;
                }
                else if (ang <= 90 && ang > 45) {
                    return 0;
                }
            case 2:
                if (ang < 45 && ang >= 0) {
                    return 2;
                }
                else if (ang <= 90 && ang > 45) {
                    return 0;
                }
                break;
            case 3:
                if (ang <= -45 && ang > -90) {
                    return 1;
                }
                else if (ang <= 0 && ang > -45) {
                    return 2;
                }
                break;
            case 4:
                if (ang <= -45 && ang >= -90) {
                    return 1;
                }
                else if (ang <= 0 && ang > -45) {
                    return 3;
                }
                break;
        }
    };
    /*
    计算两点关系所形成的象限
    以P1 作为坐标原点，P2为设定点，判断P2相对于P1时所在象限
    */
    __egretProto__.quadrant = function (p1, p2) {
        if (p2.x >= p1.x) {
            if (p2.y <= p1.y) {
                return 1;
            }
            else {
                return 4;
            }
        }
        else {
            if (p2.y <= p1.y) {
                return 2;
            }
            else {
                return 3;
            }
        }
    };
    return Gesture;
})();
Gesture.prototype.__class__ = "Gesture";
//# sourceMappingURL=Gesture.js.map