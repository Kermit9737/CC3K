#include<iostream>
#include<string>
//#include"Potion.h"
using namespace std;
class Player
{
private:
    string Character;//����
    double Attack;//������
    double Defense;//������
    double HP;//����ֵ
    double Max_HP;//�������ֵ
    int Location[2];//��ҵ�λ��
    int Gold;//���Я���Ľ�Ǯ
    int Level;//��ҵ�¥����
public:
    Player();
    int* get_location();//������ҵĵ�ַ��¥�� int[3]{¥�㣬�����꣬������}
    void select_character();//ѡ������
    bool judge_alive();//�ж��Ƿ����
    string get_user_move(string _move);//���ܼ��̵�����
    void set_location(int _location[2]);//�޸���ҵ�λ��
    int deal_damage();//������ҵĹ�����
    void lose_HP(int _damage);//������˵��˺���������֮���޸�����ֵ
//    void get_HP(Potion _potion);//����һ��ҩˮ���޸�HP
    void recover(int _recover_HP);//�ظ�Ч��

    ~Player();
};

