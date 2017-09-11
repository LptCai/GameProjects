class Game extends egret.DisplayObjectContainer{
	public constructor() {
        super();
        this.init();
	}
    private GameStart: StartPanal;//开始界面
    private ui: UIPanal;//选关界面
    private GameOver: OverPanal;//游戏结束界面
    private _help:Help;//帮助界面
    private pro: Prologue;//序章故事界面
    private epi: Epilogue;
    private gmap: Gmap;
    private gmap1: Gmap1;
    private gmap2: Gmap2;
    private gmap3: Gmap3;
    private gmap4: Gmap4;
    private gmap5: Gmap5;
    private gmap6: Gmap6;
    private gmap7: Gmap7;
    private gmap8: Gmap8;
    private gmap9: Gmap9;
    private gmap10: Gmap10;
    private gmap11: Gmap11;
    private s:egret.Shape;
    private g: Gesture;
    private init()
    { 
       this.GameStart = new StartPanal();
       this.GameStart.x = 0;
       this.GameStart.y = 0;
       this.GameStart.width = 480;
       this.GameStart.height = 800;
       this.addChild(this.GameStart); 
       
       //关卡选择手势识别，目前是左右滑动，应该设置为顺逆时针判别比较适合时钟面板
       this.s = new egret.Shape();
       this.g = new Gesture(1);
       this.g.addEvent(this.s);
       
       this.addEvent();          
    }
    private addEvent()
    { 
        DataStruct.stage.addEventListener("prologue",this.prologue,this);
        DataStruct.stage.addEventListener("startgame",this.startgame,this);
        DataStruct.stage.addEventListener("tomenu",this.Tomenu,this);
        DataStruct.stage.addEventListener("nowlevel",this.Intolevel,this);
        DataStruct.stage.addEventListener("epilogue",this.epilogue,this);
        DataStruct.stage.addEventListener("gameover",this.over,this);
        DataStruct.stage.addEventListener("help",this.help,this);
        DataStruct.stage.addEventListener("back_to_now",this.removeMenu,this);
        DataStruct.stage.addEventListener("quit_help",this.quithelp,this);
    }
    private help()
    { 
        this._help = new Help();
        this.addChild(this._help);
    }
    private quithelp()
    { 
        if(this._help != null && this._help.parent != null)
        { 
            this.removeChild(this._help);
        }
    }
    private removeMenu()
    { 
        if(this.ui != null && this.ui.parent != null)
        { 
            this.removeChild(this.ui);
        }
    }
    private prologue()
    { 
        if(this.GameStart != null && this.GameStart.parent != null)
        { 
            this.removeChild(this.GameStart);
        }
        this.pro = new Prologue();
        this.addChild(this.pro);
    }
    private epilogue()
    { 
        if(this.gmap11 != null && this.gmap11.parent != null)
        {
            this.removeChild(this.gmap11);
        }   
        this.epi = new Epilogue();
        this.addChild(this.epi);
    }
    private startgame()
    { 
        
        if(this.pro!=null&&this.pro.parent != null)
        { 
           this.removeChild(this.pro);
        }
     if(this.GameOver!=null&&this.GameOver.parent!=null)
     { 
         this.removeChild(this.GameOver);
     }
        DataStruct.levelNow = 0;
        DataStruct.Gdir = 1;
        this.gmap = new Gmap();
        this.addChild(this.gmap);
    }
    private Tomenu()
    {
        this.ui = new UIPanal();
        this.addChild(this.ui);               
    }
    private Intolevel()
    {
        if(this.ui!=null&&this.ui.parent != null)
        { 
            this.removeChild(this.ui);
        }
        if(this.GameOver!=null&&this.GameOver.parent!=null)
        { 
            this.removeChild(this.GameOver);
        }
        this.clearGmap();
        //初始化地图数据为当前关卡
        switch(DataStruct.levelNow){
           case 0:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap = new Gmap();
                   this.addChild(this.gmap);
                   break;
               }
           case 1:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap1 = new Gmap1();
                   this.addChild(this.gmap1);
                   break;
               }
           case 2:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap2 = new Gmap2()
                   this.addChild(this.gmap2);
                   break;
               }
           case 3:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap3 = new Gmap3();
                   this.addChild(this.gmap3);
                   break;
               }
           case 4:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap4 = new Gmap4();
                   this.addChild(this.gmap4);
                   break;
               }
           case 5:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap5 = new Gmap5();
                   this.addChild(this.gmap5);
                   break;
               }
           case 6:
               {
                   DataStruct.Gdir = 0;
                   DataStruct.Gy = DataStruct.Gsize * -1;
                   DataStruct.Gx = 0;
                   this.gmap6 = new Gmap6();
                   this.addChild(this.gmap6);
                   break;
               }
           case 7:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap7 = new Gmap7();
                   this.addChild(this.gmap7);
                   break;
               }
           case 8:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap8 = new Gmap8();
                   this.addChild(this.gmap8);
                   break;
               }
           case 9:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap9 = new Gmap9();
                   this.addChild(this.gmap9);
                   break;
               }
           case 10:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap10 = new Gmap10();
                   this.addChild(this.gmap10);
                   break;
               }
           case 11:
               {
                   DataStruct.Gdir = 1;
                   DataStruct.Gy = DataStruct.Gsize * 1;
                   DataStruct.Gx = 0;
                   this.gmap11 = new Gmap11();
                   this.addChild(this.gmap11);
                   break;
               }
           default:
               break;
        }
    }
    private over()
    { 
        this.clearGmap();       
        this.GameOver = new OverPanal();
        this.addChild(this.GameOver);
    }
    private clearGmap()
    { 
          if(this.gmap!=null&&this.gmap.parent!=null)
          { 
               this.removeChild(this.gmap);
          }
          if(this.gmap1!=null&&this.gmap1.parent!=null)
          { 
               this.removeChild(this.gmap1);
          }
          if(this.gmap2!=null&&this.gmap2.parent!=null)
          { 
               this.removeChild(this.gmap2);
          }
          if(this.gmap3!=null&&this.gmap3.parent!=null)
          { 
               this.removeChild(this.gmap3);
          }
          if(this.gmap4!=null&&this.gmap4.parent!=null)
          { 
               this.removeChild(this.gmap4);
          }
          if(this.gmap5!=null&&this.gmap5.parent!=null)
          { 
              this.removeChild(this.gmap5);
          }
          if(this.gmap6!=null&&this.gmap6.parent!=null)
          { 
               this.removeChild(this.gmap6);
          }
          if(this.gmap7!=null&&this.gmap7.parent!=null)
          { 
               this.removeChild(this.gmap7);
          }
          if(this.gmap8!=null&&this.gmap8.parent!=null)
          { 
                this.removeChild(this.gmap8);
          }
          if(this.gmap9!=null&&this.gmap9.parent!=null)
          { 
               this.removeChild(this.gmap9);
          }
          if(this.gmap10!=null&&this.gmap10.parent!=null)
          { 
              this.removeChild(this.gmap10);
          }
          if(this.gmap11!=null&&this.gmap11.parent!=null)
          { 
               this.removeChild(this.gmap11);
          }
    }

}
