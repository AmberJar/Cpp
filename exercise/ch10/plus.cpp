#include <iostream>
using namespace std;

void plus(int i)
{
    auto plus_ = [i](int j){ return i + j;};
}