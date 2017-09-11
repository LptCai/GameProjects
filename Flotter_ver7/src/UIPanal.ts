
class UIPanal extends egret.Sprite {
    public constructor() {
        super();
        this.init();
    }
    private levelShow: egret.Bitmap;//关卡图片
    private bg: egret.Bitmap;//背景
    private quit: egret.Bitmap;
    private help: egret.Bitmap;
    private l: number = 0;
    private intolevel_btn: egret.Bitmap;
    private s: egret.Shape;
    private g: Gesture;
    private levelnum: egret.BitmapText;
    private levelTen: egret.Bitmap;

    private init() { 
        
        console.log("ui");
        //加载背景图片
        this.bg = new egret.Bitmap();
        this.bg.texture = RES.getRes("ui_bg_png");
        this.bg.x = 0;
        this.bg.y = 0;
        this.bg.width = 360;
        this.bg.height = 400;
        this.addChild(this.bg);
        
        
        this.l = DataStruct.levelNow;
        //加载关卡图片
        this.levelShow = new egret.Bitmap();
        this.levelShow.texture = RES.getRes(DataStruct.level[this.l]);
        this.levelShow.x = 30;
        this.levelShow.y = 40;
        this.levelShow.width = 300;
        this.levelShow.height = 260;
        this.addChild(this.levelShow);
      
        //加载退出按钮
        this.quit = new egret.Bitmap();
        this.quit.texture = RES.getRes("quit_up_png");
        this.quit.x = 10;
        this.quit.y = 300;
        this.addChild(this.quit);
        this.quit.touchEnabled = true;
        this.quit.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.lbtndown,this);
        this.quit.addEventListener(egret.TouchEvent.TOUCH_END,this.lbtnup,this);
                
        //加载帮助按钮
        this.help = new egret.Bitmap();
        this.help.texture = RES.getRes("help_up_png");
        this.help.x = 300;
        this.help.y = 300;
        this.addChild(this.help);
        this.help.touchEnabled = true;
        this.help.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.rbtndown,this);
        this.help.addEventListener(egret.TouchEvent.TOUCH_END,this.rbtnup,this);
 
        //加载当前关卡字符集罗马数字1-10
        this.levelnum = new egret.BitmapText();
        this.levelnum.font = RES.getRes("levelfont_fnt");
        this.levelnum.text = this.l.toString();   
        this.addChild(this.levelnum);
        this.levelnum.y = 315;
        this.levelnum.x =165;
        this.levelnum.scaleX = 0.3;
        this.levelnum.scaleY = 0.3;
        this.levelnum.touchEnabled = true;
        this.levelnum.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.selected,this);
        this.levelnum.addEventListener(egret.TouchEvent.TOUCH_END,this.startlevel,this);
        
        //加载当前选关图片10——11；//由于罗马数字到10以后不能通过数字组合实现所以要特别加载11和12两个数字
        this.levelTen = new egret.Bitmap();
        this.levelTen.texture = RES.getRes(DataStruct.leveltext[0]);
        this.levelTen.x = 165;
        this.levelTen.y = 315;
        this.levelTen.scaleX = 0.3;
        this.levelTen.scaleY = 0.3;
        this.levelTen.touchEnabled = true;
        this.levelTen.addEventListener(egret.TouchEvent.TOUCH_BEGIN,this.selected,this);
        this.levelTen.addEventListener(egret.TouchEvent.TOUCH_END,this.startlevel,this);
               
       //自身数据
        this.x = 60;
        this.y = 60;
        this.width = 360;
        this.height = 400;
    
        DataStruct.stage.addEventListener("level_increace",this.levelinc,this);//关卡增加
        DataStruct.stage.addEventListener("level_deline",this.leveldec,this);//关卡减少       
        
    }
    private startlevel()
    {      
        if(this.l < 10)
        {
            this.levelnum.font = RES.getRes("levelfont_fnt");
        } else 
        { 
            this.levelTen.texture=RES.getRes(DataStruct.leveltext[this.l-10])
        }
        if(DataStruct.levelclock[this.l] == true) {
            DataStruct.levelNow = this.l;
            DataStruct.stage.dispatchEvent(new egret.Event("nowlevel"));
        }
    }
    private selected()
    { 
        if(this.l < 10) 
        {           
            this.levelnum.font = RES.getRes("levelfont_down_fnt");
        } else { 
            this.levelTen.texture = RES.getRes(DataStruct.levelselect[this.l - 10]);
        }
    }
  
    private levelinc()
    { 
        if(this.l <11) {
            this.l++;
            if(this.l < 10) {
                if(this.levelTen != null && this.levelTen.parent != null) {
                    this.removeChild(this.levelTen);
                }
                             
                this.addChild(this.levelnum);  
                this.levelnum.text = this.l.toString();
            } else { 
                if(this.levelnum != null && this.levelnum.parent != null)
                { 
                    this.removeChild(this.levelnum);
                }
                this.addChild(this.levelTen);
                this.levelTen.texture = RES.getRes(DataStruct.leveltext[this.l - 10]);             
            }
            this.levelShow.texture = RES.getRes(DataStruct.level[this.l]);
        }
    }
    private leveldec()
    { 
        if(this.l >0) {           
            this.l--;
            if(this.l < 10) {
                if(this.levelTen != null && this.levelTen.parent != null)
                { 
                    this.removeChild(this.levelTen);
                }
                 this.addChild(this.levelnum);

                this.levelnum.text = this.l.toString();
            } else
            { 
                if(this.levelnum != null && this.levelnum.parent != null)
                { 
                    this.removeChild(this.levelnum);
                }

                    this.addChild(this.levelTen);

                this.levelTen.texture = RES.getRes(DataStruct.leveltext[this.l - 10]);     
            }
            this.levelShow.texture = RES.getRes(DataStruct.level[this.l]);
        }
    }
    private lbtnup() {
        this.quit.texture = RES.getRes("quit_up_png");
        DataStruct.stage.dispatchEvent(new egret.Event("back_to_now"));
    }
    private lbtndown()
    { 
        this.quit.texture = RES.getRes("quit_down_png");    
    }
    private rbtnup()
    { 
        this.help.texture = RES.getRes("help_up_png");
        DataStruct.stage.dispatchEvent(new egret.Event("help"));
    }
    private rbtndown()
    { 
        this.help.texture = RES.getRes("help_down_png");    
    }   
}
