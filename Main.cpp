#include<iostream>
#include<string>
#include<time.h>
#include<random>
//#include<Windows.h>
#include<stdlib.h>

#include"GameBroad.h"
//#include"Player.h"
//#include"NPC.h"
//#include"Potion.h"
//#include"Gold.h"

using namespace std;


int main()
{
    cout << "main loaded" << endl;
    //从此开始游戏循环
    while (true) 
    {
        GameBroad New_game;//定义一个新的游戏
        cout << "Game now started" << endl;
        Player New_player;//定义一个新的玩家
        New_game.start_game(New_player);//调用游戏启动方法，游戏的全部内容在此方法中，游戏结束时退出该方法
        while (true)
        {
            char Choice;//定义一个选择游戏是否继续的变量
            cout << "Do you want to play again?[Y/N]" << endl;
            cin >> Choice;
            if (Choice == 'Y')//是则继续
                continue;
            else if (Choice == 'N')//不是则退出
                return 0;
            else//其他都是错误指令
                cout << "Command error,please input again." << endl;
        }
    }
    return 0;
}

//int* creat_map_random() {                     //用于产生随机的一个数对
//   srand((int)time(0));
//    int _random[2];
//    _random[0] = rand() % 79;//产生0-78的随机数
//    _random[1] = rand() % 30;//产生0-29的随机数
//    return _random;
//}