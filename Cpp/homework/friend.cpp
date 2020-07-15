#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CCar;
class CDriver{
    public:
        void ModifyCar(CCar * pCar);
};

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

    //友元函数
    friend int MostExpensiveCar(CCar cars[], int total);
    friend void CDriver::ModifyCar(CCar * pCar);

    public:
        //初始化列表
        CCar(){cout << "CCar contructor" << endl;}
        CCar(int p, int tr, int tw);
        CCar(){cout << "CCar destructor" << endl;}
};

/*CCar::CCar(int p, int tr, int w):price(p), tyre(tr,w){

};*/

void CDriver::ModifyCar(CCar * pCar)
{
    (*pCar).price += 1000;
}

class CDriver{
    public:
        void ModifyCar(){
            myCar.price += 1000;
        }
        CCar myCar;
        
};

int MostExpensiveCar(CCar cars[], int total)
{
    int tmpMax = 1;
    for (int i = 0; i < total; ++i)
        if(cars[i].price > tmpMax)
            tmpMax = cars[i].price;
    return tmpMax;
}

int main()
{
    //构造函数调用由外向内，析构函数刚好相反
    CCar car(20000, 17, 225);
    return 0;
}
