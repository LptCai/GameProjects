
class DataStruct {
    public constructor() {
    }
    public static get stageW(): number {
        return egret.MainContext.instance.stage.stageWidth;
    }
    public static get stageH(): number {
        return egret.MainContext.instance.stage.stageHeight;
    }
    public static get stage() {
        return egret.MainContext.instance.stage;
    }
    public static Gdir: number = 1;//0代表朝上1朝下2朝左3朝右
    public static Gx: number = 0;//重力加速度
    public static Gy: number = 10;//重力加速度
    public static Gsize: number = 10;//重力加速度大小
    public static levelNow: number = 0;//当前关卡
    public static movespeed: number = 2;//墙壁移动速度
    public static levelclock: boolean[] = [true,false,false,false,false,false,false,false,false,false,false,false];//记录当前关卡是否解锁
    //ui选关界面图
    public static level: string[] = ["ui_level1_png","ui_level2_png","ui_level3_png","ui_level4_png",
                                     "ui_level5_png","ui_level6_png","ui_level7_png","ui_level8_png",
                                     "ui_level9_png","ui_level10_png","ui_level11_png","ui_level12_png"];
    //关卡背景贴图
    public static levelmapbg: string[] = ["l0_bg_png","l1_bg_png","l2_bg_png","l3_bg_png",
                                              "l4_bg_png","l5_bg_png","l6_bg_png","l7_bg_png",
                                              "l8_bg_png","l9_bg_png","l10_bg_png","l11_bg_png"];
    //人物贴图
    public static roletex: string[] = ["roleu_png","roled_png","rolel_png","roler_png"];
    //传送门贴图，贴图没有画完所以目前是全部一样
    public static gates: string[] = ["gate0_png","gate1_png","gate2_png","gate3_png",
                                     "gate0_png","gate1_png","gate1_png","gate1_png",
                                     "gate1_png","gate1_png","gate1_png","gate1_png"];
    //贴图没有画完，所以所有记忆球贴图一样
    public static balls_0: string[] = ["memoryball0_0_png","memoryball0_0_png","memoryball0_0_png","memoryball0_0_png"];
    public static balls_1: string[] = ["memoryball0_1_png","memoryball0_1_png","memoryball0_1_png","memoryball0_1_png"];
    //选关的关卡罗马数字
    public static leveltext: string[] = ["10_up_png","11_up_png"];
    public static levelselect: string[] = ["10_png","11_png"];
    //结束面板的时钟
    public static overclock: string[] = ["ui_level1_png","ui_level2_png","ui_level3_png","ui_level4_png",
                                          "ui_level5_png","ui_level6_png","ui_level7_png","ui_level8_png",
                                          "ui_level9_png","ui_level10_png","ui_level11_png","ui_level12_png"];
    //界面上方显示的信息，对应于记忆球的testlabel
    public static memorytex: string[] = ["在围墙之间跳跃，找回遗失的记忆","If you forget","the first time I met you at a library","you must know it would happen",
        "新生的你在围墙之内，无所畏惧","万般跳跃，囿于严密守护","如痴儿般仰望世界","落在无限的可能中，也落在未知的坠落中",
        "如风拂新绿浅漾，你静静长大","你以为这是你的旅程","你肆意地侍弄魔法","森林深处，精灵泉的力量在枯竭","你只顾着前行，忘却生长的森林",
        "青春是一场盛宴，你以为它存在无限可能","你忘却的森林，一点点淡出","青春有无限可能，也有万丈深渊",
        "多少关系都有相似的轨迹：远而近到近而远","精灵追逐着尘俗，最后也会忘却尘俗","徘徊，追逐，直至打开心门",
        "从生活的谷底回归，再度徘徊","也下一个明天就能看到希望"
       ];
}