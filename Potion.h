#include<iostream>
#include<string>
using namespace std;
enum TYPE{RH,BA,BD,PH,WA,WD};

class Potion
{
private:
//    int Property;//����ҩˮ�����滹�Ǽ���
    int Location[2];//����ҩˮ��λ��
    int Durability;//����ҩˮ�ĳ���ʱ��    �б�Ҫ��
    bool Status;//�Ƿ�����Ļ�ϴ���
    TYPE Type;//ҩˮ�����
public:
    Potion();

    virtual void set_location(int _location) = 0;//����ҩˮ��λ��
    virtual void set_detail() = 0;//����ҩˮ������

    ~Potion();
};

