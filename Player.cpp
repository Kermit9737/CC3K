#include "Player.h"
//#include"GameBroad.h"
#include<iostream>
#include<limits>

using namespace std;



Player::Player()
{
    cout << "Player loaded" << endl;
}


Player::~Player()
{
    cout << "Player closed" << endl;
}

void Player::select_character()
{
    bool flag = true;
    while (flag)
    {
        cout << "Choose your race for your fight:\n"
            "[s]hade   - HP: 125, Atk: 25, Def: 25\n"
            "[d]row    - HP: 150, Atk: 25, Def: 15\n"
            "[v]ampire - HP: 50,  Atk: 25, Def: 15\n"
            "[t]roll   - HP: 120, Atk: 25, Def: 15\n"
            "[g]oblin  - HP: 110, Atk: 15, Def: 20\n"
            << endl;
        char Choice = 's';//设置默认种族
        cin >> Choice;
        switch (Choice)
        {
        case 's': {
            Character = "shade";
            HP = 125;       //生命值
            Attack = 25;//攻击力
            Defense = 25;//防御力
            Max_HP = 125;//最大生命值
            Gold = 0;//初始金币
            Level = 1;//所在的楼层
            flag = false; 
            break; }
        case'd': {
            Character = "drow";
            HP = 150;       //生命值
            Attack = 25;//攻击力
            Defense = 15;//防御力
            Max_HP = 150;//最大生命值
            Gold = 0;//初始金币
            Level = 1;//所在的楼层
            flag = false;
            break; }
        case'v': {
            Character = "vampire";
            HP = 50;       //生命值
            Attack = 25;//攻击力
            Defense = 25;//防御力
            Max_HP = INT_MAX;//最大生命值
            Gold = 0;//初始金币
            Level = 1;//所在的楼层
            flag = false;
            break; }
        case't': {
            Character = "troll";
            HP = 125;       //生命值
            Attack = 25;//攻击力
            Defense = 15;//防御力
            Max_HP = 125;//最大生命值
            Gold = 0;//初始金币
            Level = 1;//所在的楼层
            flag = false;
            break; }
        case'g': {
            Character = "goblin";
            HP = 110;       //生命值
            Attack = 15;//攻击力
            Defense = 20;//防御力
            Max_HP = 110;//最大生命值
            Gold = 0;//初始金币
            Level = 1;//所在的楼层
            flag = false;
            break; }
        default: {
            cout << "The race you chose has not been developed yet,"
                "please choose another one." << endl;
            break; }
        }
    }

}

void Player::set_location(int _location[2]) {
    Location[0] += _location[0];
    Location[1] += _location[1];
}