#include <iostream>
using namespace std;

class Skill{
    public:
    Skill(int n){}
};

class FlyBug:public Bug{
    int nWings;
    Skill sk1, sk2;

    public:
    FlyBug(int legs, int color; int wings);
};

FlyBug::FlyBug(int legs, int color, int wings):
    Bug(legs, color), sk1(5), sk2(color){
        nWings = wings;
    }