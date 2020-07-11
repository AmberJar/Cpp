#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string first_name, last_name;

    first_name = "Pengcheng";
    last_name = "Fang";

    string guess_first, guess_last;

    bool go_for_it;
    bool answer;
    int count = 0;

    while (go_for_it)
    {
        cout <<"Input your guess of the first name: ";
        cin >> guess_first;

        cout << "Please enter your guess of the last name: ";
        cin >> guess_last;

        if (first_name == guess_first && last_name == guess_last)
        {
            //guess correctly
            answer = true;
        }
        else
        {
            //guess wrongly
            answer = false;
            count++;
        }

        if (answer)
        {
            switch (count)
            {
                case 0:
                    cout << "Be my wife!\n";
                    break;
                case 1:
                    cout << "Nice boya!\n";
                    break;
                case 2:
                    cout << "Fairly good!\n";
                    break;
                default:
                    cout << "Good!\n";
                    break;
            }

            go_for_it = false;
        }
        else
        {
            switch (count)
            {
                case 1:
                    cout << "Oops! Nice guess but not quite it.\n";
                    break;
                case 2:
                    cout << "Hmm. Sorry. Wrong again.\n";
                    break;
                case 3:
                    cout << "Ah, this is harder than it looks, isn't it?\n";
                    break;
                default:
                    cout << "It must be getting pretty frustrating by now!\n";
                    break;
            }

            
            cout << "Want to try again? (Y/N) ";
            char user_rsp;
            cin >> user_rsp;

            if (user_rsp == 'N' || user_rsp == 'n')
            {
                cout << "It's sad!\n";
                go_for_it = false;
            }
            else if (user_rsp == 'Y' || user_rsp == 'y')
            {
                go_for_it = true;
            }
        } 
    }

    return 0;
}