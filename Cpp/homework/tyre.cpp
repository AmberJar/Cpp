#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CTyre{
    public:
        int radius;
        int width;
    public:
        CTyre(){cout << "CTyre contructor" << endl;}
        //radius = r, width = w
        CTyre(int r, int w): radius(r), width(w){ }
        ~CTyre(){cout << "CTyre destructor" << endl;}
};

class CEngine{
    
    public:
        CEngine(){cout << "CEngine contructor" << endl;}
        ~CEngine(){cout << "CEngine destructor" << endl;}
};

class CCar{ //封闭类
    private:
        //明确成员对象
        int price;
        CTyre tyre;
        CEngine engine;
    public:
        //初始化列表
        CCar(){cout << "CCar contructor" << endl;}
        CCar(int p, int tr, int tw);
        CCar(){cout << "CCar destructor" << endl;}
};
CCar::CCar(int p, int tr, int w):price(p), tyre(tr,w){

};

int main()
{
    //构造函数调用由外向内，析构函数刚好相反
    CCar car(20000, 17, 225);
    return 0;
}
