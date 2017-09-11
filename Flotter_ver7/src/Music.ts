
class Music extends egret.Sprite {
    public constructor() {
        super();
        this.init();
    }

    
    //关于声音组件
    private _sound: egret.Sound;
    private _soundbtn: egret.Bitmap=new egret.Bitmap();
    private _soundon: Boolean = false;//判断目前是否正在播放声音
    private _Timer: egret.Timer;
    private _flag: number = 0;
    
    private init() {
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
        this._soundbtn.addEventListener(egret.TouchEvent.TOUCH_TAP,this.soundswitch,this); 
        
        this._Timer = new egret.Timer(350,0);
        this._Timer.addEventListener(egret.TimerEvent.TIMER,this.soundvisible,this);
        
        this.x = 5;
        this.y = 720;
        this.width = 40;
        this.height = 40;
    }
    private soundvisible()
    { 
        if(this._soundon == true)
        { 
            if(this._flag == 0) {
                this._soundbtn.texture = RES.getRes("music_0_png");
                this._flag = 1;
            } else if(this._flag==1){
                this._soundbtn.texture = RES.getRes("music_1_png");
                this._flag = 0;
            }
        }
    }
    private soundswitch(evt: egret.TouchEvent) { 
        //点击按钮，音乐在播放和停止状态间转换
        if(this._soundon==false) {
            this._sound.play();
            this._soundon = true;
            this._Timer.start();
            //加入动画模拟声音可视化
        } else {
            this._sound.stop();
            this._soundon = false;
            //当声音暂停时，停止动画
            this._Timer.stop();
        }
    }
    
    
    
}
    
    
    

