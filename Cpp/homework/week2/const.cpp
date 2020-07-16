#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Sample
{
    public:
        int value;
        //常量对象不可以被修改
        //常量对象不能执行非常量成员函数
        //常量对象可以执行常量成员函数
        void GetValue() const;
        void func(){ };
        Sample(){ };
};

void Sample::GetValue() const
{

}

int main()
{
    const Sample o;
    //o.value = 100 error
    //o.func() error
    o.GetValue(); 
    return 0;
}