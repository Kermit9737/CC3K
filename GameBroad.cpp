#include "GameBroad.h"
#include "Player.h"
#include"NPC.h"

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<random>
using namespace std;

class Player;
class NPC;

GameBroad::GameBroad()
{
    cout << "GameBroad loaded" << endl;
}


GameBroad::~GameBroad()
{
    cout << "GameBroad closed" << endl;
}

void GameBroad:: start_game(Player&  _New_player) {
    while (true)
    {
        //开始一局游戏
        _New_player.select_character();//选择种族
        _New_player.set_location(this->creat_randoms(_New_player.get_level()));
        //把GameBroad产生的随机数传入，并修改location
        this->get_map();
        //this->print_map(_New_player);//只负责将地图打印出来
        this->creat_items();
        while (true) {
            //交互循环
            this->refresh_screen();
            string Cmd = this->get_cmd();
            if (this->run_cmd(_New_player,this->judge_cmd(Cmd)) == -2) {
                //重新开始游戏
                break;
            }
            if (this->judge_win() == Win){
                cout << "Congratulations!" << endl;
                break;
            }
            else if (this->judge_win() == Lose){
                cout << "You lose." << endl;
                break;
            }
            else if (this->judge_win() == Playing){
                continue;
            }
        }

    }
}

int* GameBroad::creat_randoms(int _level)
{
    //产生随机数int[2]并返回
    bool Legal = false;
    while (Legal != true)
    {
        srand((int)time(0));
        int _random[2];
        _random[0] = rand() % 79;//产生0-78的随机数
        _random[1] = rand() % 30;//产生0-29的随机数
        Legal = this->judge_elements_legal(_level,_random);//判断产生的随机地址是否合法，合法Legal变为true
        if (Legal)
            return _random;
    }
}

bool GameBroad :: judge_elements_legal(int _level,int _random[2]) {
    //判断生成的随机地址受否合法，合法返回true
    return true;
}

void GameBroad::get_map() {
    char map[80][30];
    char c;//临时变量。
    int cnt = 0; //标记目前读到几个字节。
    FILE* fp;

    fp = fopen("testfloor.txt", "r"); //打开文件。
    for (int i = 0; i < 30; i++)
    {
        for (cnt = 0; cnt < 80; cnt++)
        {
            c = fgetc(fp); //读一个字节。
            map[cnt][i] = c;//赋值到字符数组中。
        }
    }
    fclose(fp);//关闭文件。
    for (int i = 0; i < 30; i++)
    {
        for (cnt = 0; cnt < 80; cnt++)
        {
            cout << map[cnt][i];
        }
    }

}

int GameBroad::run_cmd(Player& _New_Player,string _cmd) {//返回是否重启游戏
    if (_cmd == "h"){
        cout << "Directions: [no]rth, [so]uth, [ea]st, [we]st, [ne], [nw], [se], [sw]\n"
            "a <Direction>: attack enemy at given direction\n"
            "u <direction>: use potion at given direction\n"
            "r : restart game\n"
            "q : quit game\n"
            "h : see help instructions" << endl;
        this->run_cmd(_New_Player,this->judge_cmd(_cmd));//如果输入h，显示信息，然后重新调用自己
    }
    else if (_cmd == "q") {
        exit(0);
    }
    else if (_cmd == "r") {
        return -2;//返回-2代表重启游戏
    }
    else if (_cmd == "no" || _cmd == "so" || _cmd == "ea" || _cmd == "we" || _cmd == "ne" || _cmd == "nw" || _cmd == "se" || _cmd == "sw") {
        //如果是移动指令，则把指令传递给_New_Player，调用其内置函数修改位置
        if (this->judge_move_legal(_New_Player,_cmd) == true) {
            //如果玩家选择的方向可以走，把数据传给set_location
            if (_cmd == "no") {
                int _location[2] = { 0,1 };//x不变，y+1
                _New_Player.set_location(_location);//传回数组进行修改
            }
            if (_cmd == "so") {
                int _location[2] = { 0,-1 };
                _New_Player.set_location(_location);
                if (this->judge_attacked() == true){
                    NPC* NPC_string = this->return_NPC();//返回在玩家身边的NPC,作为一个数组
                    int Count = this->NPCstring_len(NPC_string);//获得NPC_string的长度
                    for (int i = 0; i < Count; i++) {
                        this->game_ref_injured(_New_Player, NPC_string[i]);//被攻击使用
                        //_New_Player.lose_HP(NPC_string[i].deal_damage());
                    }


                }
            }
            if (_cmd == "ea") {
                int _location[2] = { 1,0 };
                _New_Player.set_location(_location);
            }
            if (_cmd == "we") {
                int _location[2] = { -1,0 };
                _New_Player.set_location(_location);
            }
            if (_cmd == "ne") {
                int _location[2] = { 1,1 };
                _New_Player.set_location(_location);
            }
            if (_cmd == "nw") {
                int _location[2] = { -1,1 };
                _New_Player.set_location(_location);
            }
            if (_cmd == "se") {
                int _location[2] = { 1,-1 };
                _New_Player.set_location(_location);
            }
            if (_cmd == "sw") {
                int _location[2] = { -1,-1 };
                _New_Player.set_location(_location);
            }
        } 
        else if (this->judge_move_legal(_New_Player, _cmd) == false)//如果这个位置不可以走
        {
            cout << "不可以走这里" << endl;
            return 0;//什么都不做
         }
    }
 
}