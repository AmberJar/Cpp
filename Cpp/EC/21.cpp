#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    return 0;
}

bool pentagonal(int pos, int &elem)
{
    if (pos <= 0 || pos > 1024)
        {elem = 0; return false;}

    for (int ix = 1; ix <= pos; ++ix)
    {
        elem = ix * (3 * ix - 1)/ 2;

    }
}

const vector<int>* pent_seq()
{
    
}