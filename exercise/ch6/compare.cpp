#include <iostream>
#include <cstring>
using namespace std;

int compare(const int i, const int *j)
{
    if (i > *j)
        return i;
    
    else
    {
        return *j;
    }
}

void exchange(int *&pa, int *&pb)
{
    int *tmp = pa;
    pa = pb;
    pb = tmp;
}