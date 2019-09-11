#include<iostream>
#include<string>
using namespace std;
enum ATTITUDE{Friendly,Opposed};
class NPC
{
private:
    double Attack;//������
    double Defense;//������
    double HP;//����ֵ
    double Max_HP;//�������ֵ
    int Location[2];//NPC��λ��
    ATTITUDE Attitude;//NPC��̬��
    int Gold;//NPCЯ���Ľ�Ǯ
    bool Status;//�Ƿ��ڵ�ͼ�ϴ���
public:
    NPC();

    virtual void set_location(int _location[2]) = 0;//���ó�ʼλ��
    virtual int deal_damage() = 0;//����NPC�Ĺ�����
    virtual void lose_HP(int _damage) = 0;//������ҵĹ�����������õ��˺�ֵ��ִ�е�Ѫ����
    virtual bool judge_move_legal(int _move[2]) = 0;//�ж��ƶ��Ƿ�Ϸ��������Ƿ�Ϸ�
    virtual void move_NPC() = 0;//�����������ִ���ƶ�
    ~NPC();
};
