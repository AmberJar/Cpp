#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

class CStudent{
    public: int nAge;
};

ostream &operator<<( ostream &o, const CStudent &s)
{
    o << s.nAge;
    return o;
}

int main()
{
    CStudent s;
    s.nAge = 5;
    cout << s << "hello";
    return 0;
}