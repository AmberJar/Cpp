#include <iostream>
#include <vector>

using namespace std;

class String{
    private:
        char *p;
    
    public:
        String(){
            p = new char[10];
        }
        ~String();
};

String ::~String(){
    delete []p;
}

class Ctest{
    public:
    ~Ctest(){ cout << "destructor called" << endl; }
};

int main()
{
    Ctest array[2];
    cout << "End Main" << endl;
    return 0;
}