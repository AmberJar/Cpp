#include <iostream>
#include <vector>
using namespace std;

int foo(int, int);
int bar(int, int);

int main()
{
    vector<int (*)(int, int)> vf;
}


int foo(int a, int b)
{
    std::cout << "Called foo(" << a << ", " << b << ")" << std::endl;
}

int bar(int a, int b)
{
    std::cout << "Called bar(" << a << ", " << b << ")" << std::endl;
}