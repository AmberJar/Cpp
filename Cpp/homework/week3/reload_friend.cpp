class Complex{
    double real, imag;

    public:
        Complex(double r, double i): real(r), imag(i){};
        Complex operator+(double r);
        friend Complex operator+(double r, const Complex &c);
};
Complex Complex::operator+(double r){
    return Complex(real + r, imag);
}