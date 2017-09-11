var Music = (function (_super) {
    __extends(Music, _super);
    function Music() {
        _super.call(this);
        this._soundbtn = new egret.Bitmap();
        this._soundon = false; //判断目前是否正在播放声音
        this._flag = 0;
        this.init();
    }
    var __egretProto__ = Music.prototype;
    __egretProto__.init = function () {
        this._sound = RES.getRes("A_Fond_Wish_mp3");
        this._sound.type = egret.Sound.MUSIC;
        //按钮加载_控制是否播放声音
        this._soundbtn.texture = RES.getRes("music_0_png");
        this._soundbtn.x = 0;
        this._soundbtn.y = 0;
        this._soundbtn.width = 40;
        this._soundbtn.height = 40;
        this.addChild(this._soundbtn);
        this._soundbtn.touchEnabled = true;
        this._soundbtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.soundswitch, this);
        this._Timer = new egret.Timer(350, 0);
        this._Timer.addEventListener(egret.TimerEvent.TIMER, this.soundvisible, this);
        this.x = 5;
        this.y = 720;
        this.width = 40;
        this.height = 40;
    };
    __egretProto__.soundvisible = function () {
        if (this._soundon == true) {
            if (this._flag == 0) {
                this._soundbtn.texture = RES.getRes("music_0_png");
                this._flag = 1;
            }
            else if (this._flag == 1) {
                this._soundbtn.texture = RES.getRes("music_1_png");
                this._flag = 0;
            }
        }
    };
    __egretProto__.soundswitch = function (evt) {
        //点击按钮，音乐在播放和停止状态间转换
        if (this._soundon == false) {
            this._sound.play();
            this._soundon = true;
            this._Timer.start();
        }
        else {
            this._sound.stop();
            this._soundon = false;
            //当声音暂停时，停止动画
            this._Timer.stop();
        }
    };
    return Music;
})(egret.Sprite);
Music.prototype.__class__ = "Music";
//# sourceMappingURL=Music.js.map