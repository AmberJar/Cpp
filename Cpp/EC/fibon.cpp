#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

bool fibon_elem(int, int & );
bool print_sequence(int);

int main()
{   
    int pos;
    char ch;
    bool more = true;

    while(more)
    {
        cout << "Please enter a position: ";
        cin >> pos;

        int elem;
        if (fibon_elem(pos, elem))
            cout << "element # " << pos
                << " is " << elem << endl;
        else cout << "Sorry. Could not calculate element # "
                << pos << endl;
        
        print_sequence(pos);

        cout << "Would you like to try again? (y/n)";
        cin >> ch;

        if (ch != 'y' && ch != 'Y')
            more = false;
    }
    
    return 0;
}

bool fibon_elem(int pos, int &elem)
{
    //检查位置是否合理
    if (pos <= 0 || pos > 1024)
        {elem = 0; return false; }

    //检查位置1 和 2时， elem值为1
    elem = 1;
    int n_2 = 1, n_1 = 1;

    for (int ix = 3; ix <= pos; ++ix)
    {
        elem = n_2 + n_1;
        n_2 = n_1; n_1 = elem;

        cout << elem << (!(ix % 10) ? "\n\t" : " ");
    }
    cout << endl;

    return true;
};

bool print_sequence(int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        cerr << "Invalid position: " << pos 
             << " -- canont hanlde request!\n";
        
        return false;
    }

    cout << "The Fibonacci Sequence for "
         << pos << " positions: \n\t";

    switch(pos)
    {
        default:
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";
            break;
    }

    int elem;
    int n_2 = 1, n_1 = 1;

    for (int ix = 3; ix <= pos; ++ix)
    {
        elem = n_2 + n_1;
        n_2 = n_1; n_1 = elem;

        cout << elem << (!(ix % 10) ? "\n\t" : " ");
    }
    cout << endl;

    return true;
}