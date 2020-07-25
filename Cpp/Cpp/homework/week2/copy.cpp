#include <iostream>
#include <vector>
using namespace std;

class Complex{
        public:
            double real, imag;
        
        Complex(){}
        Complex(const Complex & c){
            real = c.real;
            imag = c.imag;
            cout << "Copy Constructor called";
        }
};
Complex c1;
Complex c2(c1);

class A
{
    public:
    A(){};
    A(A & a){
        cout << "Copy constructor called" << endl;
    }
};

void Func(A al){}
int main(){
    A a2;
    Func(a2);
    return 0;
}