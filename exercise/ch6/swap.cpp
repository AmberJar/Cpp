#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    cout << a << b << endl;

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    cout << a << b << endl;
}

int main()
{
    int a, b;

    a = 10;
    b = 20;

    swap(&a, &b);

    cout << a << " " << b <<endl;
    return 0;
}