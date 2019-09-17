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
        //��ʼһ����Ϸ
        _New_player.select_character();//ѡ������
        _New_player.set_location(this->creat_randoms(_New_player.get_level()));
        //��GameBroad��������������룬���޸�location
        this->get_map();
        //this->print_map(_New_player);//ֻ���𽫵�ͼ��ӡ����
        this->creat_items();
        while (true) {
            //����ѭ��
            this->refresh_screen();
            string Cmd = this->get_cmd();
            if (this->run_cmd(_New_player,this->judge_cmd(Cmd)) == -2) {
                //���¿�ʼ��Ϸ
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
    //���������int[2]������
    bool Legal = false;
    while (Legal != true)
    {
        srand((int)time(0));
        int _random[2];
        _random[0] = rand() % 79;//����0-78�������
        _random[1] = rand() % 30;//����0-29�������
        Legal = this->judge_elements_legal(_level,_random);//�жϲ����������ַ�Ƿ�Ϸ����Ϸ�Legal��Ϊtrue
        if (Legal)
            return _random;
    }
}

bool GameBroad :: judge_elements_legal(int _level,int _random[2]) {
    //�ж����ɵ������ַ�ܷ�Ϸ����Ϸ�����true
    return true;
}

void GameBroad::get_map() {
    char map[80][30];
    char c;//��ʱ������
    int cnt = 0; //���Ŀǰ���������ֽڡ�
    FILE* fp;

    fp = fopen("testfloor.txt", "r"); //���ļ���
    for (int i = 0; i < 30; i++)
    {
        for (cnt = 0; cnt < 80; cnt++)
        {
            c = fgetc(fp); //��һ���ֽڡ�
            map[cnt][i] = c;//��ֵ���ַ������С�
        }
    }
    fclose(fp);//�ر��ļ���
    for (int i = 0; i < 30; i++)
    {
        for (cnt = 0; cnt < 80; cnt++)
        {
            cout << map[cnt][i];
        }
    }

}

int GameBroad::run_cmd(Player& _New_Player,string _cmd) {//�����Ƿ�������Ϸ
    if (_cmd == "h"){
        cout << "Directions: [no]rth, [so]uth, [ea]st, [we]st, [ne], [nw], [se], [sw]\n"
            "a <Direction>: attack enemy at given direction\n"
            "u <direction>: use potion at given direction\n"
            "r : restart game\n"
            "q : quit game\n"
            "h : see help instructions" << endl;
        this->run_cmd(_New_Player,this->judge_cmd(_cmd));//�������h����ʾ��Ϣ��Ȼ�����µ����Լ�
    }
    else if (_cmd == "q") {
        exit(0);
    }
    else if (_cmd == "r") {
        return -2;//����-2����������Ϸ
    }
    else if (_cmd == "no" || _cmd == "so" || _cmd == "ea" || _cmd == "we" || _cmd == "ne" || _cmd == "nw" || _cmd == "se" || _cmd == "sw") {
        //������ƶ�ָ����ָ��ݸ�_New_Player�����������ú����޸�λ��
        if (this->judge_move_legal(_New_Player,_cmd) == true) {
            //������ѡ��ķ�������ߣ������ݴ���set_location
            if (_cmd == "no") {
                int _location[2] = { 0,1 };//x���䣬y+1
                _New_Player.set_location(_location);//������������޸�
            }
            if (_cmd == "so") {
                int _location[2] = { 0,-1 };
                _New_Player.set_location(_location);
                if (this->judge_attacked() == true){
                    NPC* NPC_string = this->return_NPC();//�����������ߵ�NPC,��Ϊһ������
                    int Count = this->NPCstring_len(NPC_string);//���NPC_string�ĳ���
                    for (int i = 0; i < Count; i++) {
                        this->game_ref_injured(_New_Player, NPC_string[i]);//������ʹ��
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
        else if (this->judge_move_legal(_New_Player, _cmd) == false)//������λ�ò�������
        {
            cout << "������������" << endl;
            return 0;//ʲô������
         }
    }
 
}