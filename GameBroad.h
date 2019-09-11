#include<iostream>
#include<string>
//#include"Player.h"
using namespace std;
enum JUDGE {Win,Lose,Playing};

class Player;

class GameBroad
{
private:
    char Map[5][79][30];//定义地图
    JUDGE Game_judge;//定义游戏胜利或者失败或者正在进行中
    int Dungeon_Level;//定义地牢的层数

public:
    GameBroad();

    //virtual void get_map() = 0;//从文件中读取地图，然后保存到Map[79][30]种
    //virtual void print_map() = 0;//将地图打印到屏幕上
    //virtual JUDGE judge_win() = 0;//判断是否获得胜利
    //virtual int creat_randoms() = 0;//为地图添加各种元素
    ////virtual bool judge_alive() = 0;//有必要吗？
    //virtual void start_game() = 0;//开始一局游戏（是不是应该定义常规函数？）
    //virtual void show_player() = 0;//显示玩家的位置（可不可以在refresh_screen里？）
    //virtual string get_cmd() = 0;//接受用户输入的命令，并传给处理程序
    //virtual string judge_cmd() = 0;//判定命令是否合法。如果合法，将命令返回；如果不合法，返回"Help"
    //virtual void show_help() = 0;//显示帮助界面
    //virtual void refresh_screen() = 0;//刷新屏幕
    //virtual bool judge_flght() = 0;//判断是否发生战斗。如果发生战斗，执行战斗伤害结算；若没有，返回false

    void get_map();//从文件中读取地图，然后保存到Map[79][30]中
    void print_map(Player _New_player);//将地图打印到屏幕上，判断玩家现在在第几层
    JUDGE judge_win();//判断是否获得胜利
    int* creat_randoms();//产生随机数int[2]并返回
    //bool judge_alive();//有必要吗？
    void start_game(Player& _New_player);//开始一局游戏（是不是应该定义常规函数？）
    void show_player();//显示玩家的位置（可不可以在refresh_screen里？）
    string get_cmd();//接受用户输入的命令，并传给处理程序
    string judge_cmd(string _cmd);//判定命令是否合法。如果合法，将命令返回；如果不合法，返回"Help"
    int run_cmd(Player&  _New_Player,string _cmd);//执行命令
    void show_help();//显示帮助界面
    void refresh_screen();//刷新屏幕
    bool judge_flght();//判断是否发生战斗。如果发生战斗，执行战斗伤害结算；若没有，返回false
    bool judge_elements_legal(Player _temp_player,int _random[2]);//判断生成的随机地址受否合法，合法返回true
    void creat_items();//在地图上添加物品,生成玩家,一次五层,内部调用creat_randoms()
    bool judge_move_legal(Player& _New_Player,string _move);//判断玩家选择的方向可不可以走，可以返回true
    int get_player_lever(Player _New_Player);//获得玩家现在的楼层数

    ~GameBroad();
};

