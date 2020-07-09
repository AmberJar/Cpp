#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string finalgrade;
    int grade;
    cin >> grade;

    finalgrade = (grade > 90) ? "high pass"
                                : (grade < 60) ? "fail" : "pass";

    cout << finalgrade << endl;

    cout << (grade < 60) ? "fail" : "pass"; 
    cout << ((grade < 60) ? "fail" : "pass\n"); 
    
}