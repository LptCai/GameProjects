
class TransGate extends egret.Sprite{
    public constructor(label:number,x:number,y:number) {
        {
            super();
            this.init(label,x,y);
        }
    }
    private gate: egret.Bitmap;//贴图
    private label: number;//当前传送门通往关卡标签
    private init(label:number,x:number,y:number)//传入数据，通完关卡，横纵坐标
    { 
        this.label = label;
        this.gate = new egret.Bitmap();
        this.gate.texture = RES.getRes(DataStruct.gates[this.label]);
        this.gate.x = 0;
        this.gate.y = 0;
        this.gate.width = 100;
        this.gate.height = 100;
        this.addChild(this.gate);
        
        this.x = x;
        this.y = y;
        this.width = this.gate.width;
        this.height = this.gate.height;
    }
    public getLabel():number
    { 
        return this.label;
    }	
}
