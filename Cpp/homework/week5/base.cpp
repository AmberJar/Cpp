#include <iostream>
using namespace std;

class Father{
    private:    int nPrivate;   //私有
    public:     int nPublic;    //公有
    protected:  int nProtected; //保护成员
};

class Son : public Father{
    void AccessFather(){
        nPublic = 1; //OK
        //nPrivate = 1; //Wrong
        nProtected = 1; // OK基类继承可访问
        Son f;
        f.nProtected = 1; //wrong, f不是当前的对象
    }
};

int main(){
    Father f;
    Son s;
    f.nPublic = 1;
    s.nPublic = 1;
    //f.nProtected = 1;  
    //f.private = 1;
    //s.nProtected = 1;
    //s.nPrivate = 1;
    return 0;
}