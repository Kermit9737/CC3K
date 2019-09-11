#include<iostream>
#include<string>
using namespace std;
enum TYPE{RH,BA,BD,PH,WA,WD};

class Potion
{
private:
//    int Property;//设置药水是增益还是减益
    int Location[2];//设置药水的位置
    int Durability;//设置药水的持续时间    有必要吗？
    bool Status;//是否在屏幕上存在
    TYPE Type;//药水的类别
public:
    Potion();

    virtual void set_location(int _location) = 0;//设置药水的位置
    virtual void set_detail() = 0;//设置药水的种类

    ~Potion();
};

