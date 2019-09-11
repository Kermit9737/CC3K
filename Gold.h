#include<iostream>
#include<string>
using namespace std;

class Gold
{
private:
    int Value;//金币的价值
    int Location[2];//设置金币生成的位置
//    int Status;//设置金币存在的状态，1代表存在0代表不存在

public:
    Gold();

    virtual void set_location(int _location[2]) = 0;//PlayBoard生成的地址通过此函数设定位置
    virtual void set_value() = 0;//设置金币的价值

    ~Gold();

};

