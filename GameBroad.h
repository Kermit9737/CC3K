#include<iostream>
#include<string>
//#include"Player.h"
using namespace std;
enum JUDGE {Win,Lose,Playing};

class Player;

class GameBroad
{
private:
    char Map[5][79][30];//�����ͼ
    JUDGE Game_judge;//������Ϸʤ������ʧ�ܻ������ڽ�����
    int Dungeon_Level;//������εĲ���

public:
    GameBroad();

    //virtual void get_map() = 0;//���ļ��ж�ȡ��ͼ��Ȼ�󱣴浽Map[79][30]��
    //virtual void print_map() = 0;//����ͼ��ӡ����Ļ��
    //virtual JUDGE judge_win() = 0;//�ж��Ƿ���ʤ��
    //virtual int creat_randoms() = 0;//Ϊ��ͼ��Ӹ���Ԫ��
    ////virtual bool judge_alive() = 0;//�б�Ҫ��
    //virtual void start_game() = 0;//��ʼһ����Ϸ���ǲ���Ӧ�ö��峣�溯������
    //virtual void show_player() = 0;//��ʾ��ҵ�λ�ã��ɲ�������refresh_screen���
    //virtual string get_cmd() = 0;//�����û����������������������
    //virtual string judge_cmd() = 0;//�ж������Ƿ�Ϸ�������Ϸ���������أ�������Ϸ�������"Help"
    //virtual void show_help() = 0;//��ʾ��������
    //virtual void refresh_screen() = 0;//ˢ����Ļ
    //virtual bool judge_flght() = 0;//�ж��Ƿ���ս�����������ս����ִ��ս���˺����㣻��û�У�����false

    void get_map();//���ļ��ж�ȡ��ͼ��Ȼ�󱣴浽Map[79][30]��
    void print_map(Player _New_player);//����ͼ��ӡ����Ļ�ϣ��ж���������ڵڼ���
    JUDGE judge_win();//�ж��Ƿ���ʤ��
    int* creat_randoms();//���������int[2]������
    //bool judge_alive();//�б�Ҫ��
    void start_game(Player& _New_player);//��ʼһ����Ϸ���ǲ���Ӧ�ö��峣�溯������
    void show_player();//��ʾ��ҵ�λ�ã��ɲ�������refresh_screen���
    string get_cmd();//�����û����������������������
    string judge_cmd(string _cmd);//�ж������Ƿ�Ϸ�������Ϸ���������أ�������Ϸ�������"Help"
    int run_cmd(Player&  _New_Player,string _cmd);//ִ������
    void show_help();//��ʾ��������
    void refresh_screen();//ˢ����Ļ
    bool judge_flght();//�ж��Ƿ���ս�����������ս����ִ��ս���˺����㣻��û�У�����false
    bool judge_elements_legal(Player _temp_player,int _random[2]);//�ж����ɵ������ַ�ܷ�Ϸ����Ϸ�����true
    void creat_items();//�ڵ�ͼ�������Ʒ,�������,һ�����,�ڲ�����creat_randoms()
    bool judge_move_legal(Player& _New_Player,string _move);//�ж����ѡ��ķ���ɲ������ߣ����Է���true
    int get_player_lever(Player _New_Player);//���������ڵ�¥����

    ~GameBroad();
};

