#include <iostream>
using namespace std;

bool isEven(int n)
{
    if ((n % 2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


long long pow(long long x, int n)
{
    if (n == 0)
        return 1;
    
    if (n == 1)
        return x;

    if(isEven(n))
        return pow(x * x, n / 2);
    else
    {
        return pow(x * x, n / 2) * x;
    }
    
}