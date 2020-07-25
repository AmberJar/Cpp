#include <iostream>
#include <vector>

using namespace std;

class A{
    public:
        int val;
        //todo
        A(int n = 0){val = n;}
        int& GetObj() {return val;}
};

int main()
{
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}
