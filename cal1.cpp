#include<iostream>
#include<vector>
#include<string>

int main()
{
    std::string text;

    getline(std::cin, text);

    /*for (const auto &s : text){
        std::cout << s;

        if (s.empty() || s[s.size() - 1] == '.')
            std::cout << std::endl;
        else
        {
            std::cout << " ";
        }
        
    }*/

    return 0;
}