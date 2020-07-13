#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

bool fibon_elem(int, int & );
bool print_sequence(int);
bool is_size_ok(int size);
template <typename elemType> void display_message(const string &msg, const vector<elemType> &vec);

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

template <typename elemType> void display_message(const string &msg, const vector<elemType> &vec)
{
    cout << msg;
    for (int ix =0; ix < vec.size(); ++ix)
    {
        elemType t = vec[x];
        cout << t << ' ';
    }
}

bool is_size_ok(int size)
{
    const int max_size = 1024;
    const string msg("Requested size is not supported");

    if (size <= 0 || size > max_size)
    {
        display_message(msg, size);
        return false;
    }

    return true;
}

/*void display_message(const string &msg, const vector<int> &vec)
{
    cout << msg;
    for (int ix = 0; ix < vec.size(); ++ix)
        cout << vec[ix] << ' ';
}

void display_message(const string &msg, const vector<string> &vec)
{
    cout << msg;
    for (int ix = 0; ix < vec.size(); ++ix)
        cout << vec[ix] << ' ';
    cout << '\n';
}

void display_message(const string &, const vector<string>&);*/

bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int))
{
    const vector<int> *pseq = seq_ptr(pos);

    if (!pseq)
        {elem = 0; return false;}
    if (!seq_ptr)
        display_message("Internal Error: seq_ptr is set to null!");
    elem = (*pseq)[pos - 1];
    return true;
}

