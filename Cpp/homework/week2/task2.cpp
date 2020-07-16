#include <iostream>
using namespace std;
class Sample{
    public:
        int v;
        Sample(int n):v(n){ }
    
        //todo
        Sample(Sample & c){
            v = c.v * 2;
        }
};

int main()
{
    Sample a(5);
    Sample b = a;
    cout << b.v << endl;
    return 0;
}