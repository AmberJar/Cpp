#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sum_adjacent(const vector<int> &v)
{
    if (v.size() < 2)
        return;
    
    for (decltype(v.size()) i = 0; i < v.size(); )
        cout << v[i] + v[i + 1] << '\t';
        cout << endl;
}

void sum_symmetric(const vector<int> &v)
{
    auto mid = (v.size() + 1)/2;
    for (decltype(mid) i = 0; i != mid; i++)
        cout << v[i] + v[v.size() - i] << '\t';
    
    cout << endl;
}


int main()
{
    vector<int> a;
    int i;

    while(cin >> i)
        a.push_back(i);

    sum_adjacent(a);

    return 0;
}