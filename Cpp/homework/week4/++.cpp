//有前置和后置之分 ++i, i++

#include <iostream>
#include <cstring>

using namespace std;

class CDemo{
    private:
        int n;
    public:
        CDemo(int i = 0):n(i){}
        CDemo operator++();     //前置
        CDemo operator++(int);      //后置
        operator int(){return n;}
        friend CDemo operator--(CDemo &);
        friend CDemo operator--(CDemo &, int);
};
CDemo CDemo::operator++(){
    //前置++
    n++;
    return *this;
}
CDemo CDemo::operator++(int k){
    //后置++
    CDemo tmp(*this);
    n++;
    return tmp; //返回修改前的对象
}
CDemo operator--(CDemo &d){
    //前置--
    d.n--;
    return d;
}
CDemo operator--(CDemo &d, int){
    //后置--
    CDemo tmp(d);
    d.n--;
    return tmp;
}

int main()
{
    CDemo d(5);
    cout << (d++) << ","; //等价于d.operator++(0);
    cout << d << ",";
    cout << (++d) << ","; //等价于 d.operator++();
    cout << d << endl;
    cout << (d--) << ","; //等价于 operator--(d, 0);
    cout << d << ",";
    cout << (--d) << ","; //等价于 operator--(d);
    cout << d << endl;
    return 0;
}