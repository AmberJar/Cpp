#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CTest{
    private:
        int n;
    
    public:
        CTest(){n = 1;}
        int GetValue() const {return n;}
        int GetValue() {return 2 * n;}
};

void print(const CTest & o)
{
    //使用常引用参数，此处o不是一个对象所以不会出发构造函数
    //可以节省运算量，同时使用常量引用，可以避免程序中途
    //对形参o的修改导致实参的改变
}
int main()
{
    const CTest objTest1;
    CTest objTest2;
    cout << objTest1.GetValue() << "," << objTest2.GetValue();
    return 0;
}