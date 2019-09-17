#include<iostream>
#include<string>
using namespace std;
enum ATTITUDE{Friendly,Opposed};
class NPC
{
private:
    double Attack;//攻击力
    double Defense;//防御力
    double HP;//生命值
    double Max_HP;//最大生命值
    int Location[2];//NPC的位置
    ATTITUDE Attitude;//NPC的态度
    int Gold;//NPC携带的金钱
    bool Status;//是否在地图上存在
public:
    NPC();

    virtual void set_location(int _location[2]) {};//设置初始位置
    virtual int deal_damage() {};//返回NPC的攻击力
    virtual void lose_HP(int _damage) {};//输入玩家的攻击力，计算得到伤害值并执行掉血操作
    virtual bool judge_move_legal(int _move[2]) {};//判断移动是否合法，返回是否合法
    virtual void move_NPC() {};//执行移动

    ~NPC();
};

