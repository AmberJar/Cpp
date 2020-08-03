#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3};

    for (auto it = a.begin(); it != a.end(); ++it)
        *it *= 2;
    
    for (const auto &elem : a)
        if (a.empty())
            cout << endl;
        else
        {
            cout << elem << " " << endl;
        }
        
    cout << endl;

    return 0;
}