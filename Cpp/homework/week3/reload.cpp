#include <iostream>
#include <string>

using namespace std;

/*
class Complex{
    public:
        Complex(double r = 0.0, double i = 0.0){
            real = r;
            imaginary = i;
        }

        double real;
        double imaginary;
};

Complex operator+ (const Complex &a, const Complex &b)
{
    return Complex(a.real + b.real, a.imaginary + b.imaginary);
}

Complex a(1,2), b(2,3);
Complex c = a + b;
*/

class Complex{
    public:
        Complex(double r = 0.0, double m = 0.0):
            real(r), imaginary(m){ }
        Complex operator+ (const Complex&);
        Complex operator- (const Complex&);

    private:
        double real;
        double imaginary;
};

Complex Complex::operator+(const Complex &operand2){
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex &operand2){
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

int main()
{
    Complex x, y(4.3, 8.2), z(3.3, 1.1);
    x = y + z;
    x = y - z;
    return 0;
}