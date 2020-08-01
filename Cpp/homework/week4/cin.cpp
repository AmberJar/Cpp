#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

class Complex{
    double real, imag;
    public:
        Complex(double r = 0, double i = 0):real(r), imag(i){};
        friend ostream &operator<<( ostream &os, const Complex &c);
        friend istream &operator>>( istream &is, Complex &c);
};

ostream &operator<<( ostream &os, const Complex &c)
{
    os << c.real << "+" << c.imag << "i"; //以“a+b"的形式输出
    return os;
}

istream &operator>>( istream &is, Complex &c)
{
    string s;
    is >> s; //以”a + bi"读入
    int pos = s.find("+", 0);
    string sTmp = s.substr(0, pos); //分离
    c.real = atof(sTmp.c_str());
    //atof库函数能够将const char*指针指向的内容转换成float
    sTmp = s.substr(pos + 1, s.length() - pos - 2);
    //分离出代表虚数的字符串
    c.imag = atof(sTmp.c_str());
    return is;
}