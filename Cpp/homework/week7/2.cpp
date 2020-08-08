#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double x;
    cin >> x;
    cout.setf(ios::fixed);
    cout << setprecision(5) << x << endl;
    cout.unsetf(ios::fixed);
    cout.setf(ios::scientific);
    cout << setprecision(7) << x <<endl;
    return 0;
}