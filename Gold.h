#include<iostream>
#include<string>
using namespace std;

class Gold
{
private:
    int Value;//��ҵļ�ֵ
    int Location[2];//���ý�����ɵ�λ��
//    int Status;//���ý�Ҵ��ڵ�״̬��1�������0��������

public:
    Gold();

    virtual void set_location(int _location[2]) = 0;//PlayBoard���ɵĵ�ַͨ���˺����趨λ��
    virtual void set_value() = 0;//���ý�ҵļ�ֵ

    ~Gold();

};

