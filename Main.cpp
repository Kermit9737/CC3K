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
    //�Ӵ˿�ʼ��Ϸѭ��
    while (true) 
    {
        GameBroad New_game;//����һ���µ���Ϸ
        cout << "Game now started" << endl;
        Player New_player;//����һ���µ����
        New_game.start_game(New_player);//������Ϸ������������Ϸ��ȫ�������ڴ˷����У���Ϸ����ʱ�˳��÷���
        while (true)
        {
            char Choice;//����һ��ѡ����Ϸ�Ƿ�����ı���
            cout << "Do you want to play again?[Y/N]" << endl;
            cin >> Choice;
            if (Choice == 'Y')//�������
                continue;
            else if (Choice == 'N')//�������˳�
                return 0;
            else//�������Ǵ���ָ��
                cout << "Command error,please input again." << endl;
        }
    }
    return 0;
}

//int* creat_map_random() {                     //���ڲ��������һ������
//   srand((int)time(0));
//    int _random[2];
//    _random[0] = rand() % 79;//����0-78�������
//    _random[1] = rand() % 30;//����0-29�������
//    return _random;
//}