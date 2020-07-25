#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Student{
    private:
        char name[100], number[100];
        int age, avg_year1, avg_year2, avg_year3, avg_year4;  
    
    public:
        void Init(char name_[100], int age_, char number_[100],
            int avg_year1_, int avg_year2_, int avg_year3_, int avg_year4_){
                strcpy(name, name_);
                age = age_;
                strcpy(number, number_);
                avg_year1 = avg_year1;
                avg_year2 = avg_year2;
                avg_year3 = avg_year3;
                avg_year4 = avg_year4; 
            }
        void Message(){
            cout << name << ',' << age << number << ',' << (avg_year1 + avg_year2 + avg_year3 + avg_year4) / 4 << endl;
        }         
};

int main(int argc, char *argv[])
{
    char name[100], number[100];
    char k;
    int age, avg_year1, avg_year2, avg_year3, avg_year4;

    cin.getline(name, 100, ',');
    cin >> age >> k;
    cin.getline(number, 100, ',');
    cin >> avg_year1 >> k >> avg_year2 >> k >> avg_year3 >> k >> avg_year4;
    Student S;
    S.Init(name, age, number, avg_year1, avg_year2, avg_year3, avg_year4);
    S.Message();
    int a;
    return 0;
}
