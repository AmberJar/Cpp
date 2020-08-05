#include <iostream>
#include <vector>
#include <string>
using namespace std;

void resetInt(int &i){
    i = 0;
}

int main(){
    int a;
    a = 10;
    cout << "before reset: " << a << endl;
    resetInt(a);
    cout << "after reset: " << a << endl;

    return 0;
}