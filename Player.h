#include<iostream>
#include<string>
//#include"Potion.h"
using namespace std;
class Player
{
private:
    string Character;//种族
    double Attack;//攻击力
    double Defense;//防御力
    double HP;//生命值
    double Max_HP;//最大生命值
    int Location[2];//玩家的位置
    int Gold;//玩家携带的金钱
    int Level;//玩家的楼层数
public:
    Player();
    int* get_location();//返回玩家的地址，楼层 int[3]{楼层，横坐标，纵坐标}
    void select_character();//选择种族
    bool judge_alive();//判断是否活着
    string get_user_move(string _move);//接受键盘的输入
    void set_location(int _location[2]);//修改玩家的位置
    int deal_damage();//返回玩家的攻击力
    void lose_HP(int _damage);//传入敌人的伤害量，计算之后修改生命值
//    void get_HP(Potion _potion);//传入一个药水，修改HP
    void recover(int _recover_HP);//回复效果

    ~Player();
};

