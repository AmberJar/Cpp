#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CStudent{
    private:
        string name;
        string id;  //学号
        char gender;    //性别F女 M男
        int age;
    
    public:
        void PrintInfo(){};
        void SetInfo( const string &name_, const string &id_, int age_, char gender_);
        string GetName(){ return name;}
};

class CUndergraduateStudent: public CStudent{
    private:
        string department;

    public:
        void QualifiledForBaoyan(){
            //给予保研资格
            cout << "qualified for baoyan" << endl;
        }
        void PrintInfo(){
            CStudent::PrintInfo(); //调用基类的PrintInfo
            cout << "Department:" << department << endl;
        }
        void SetInfo( const string &name_, const string &id_, int age_, char gender_, const string &department_){
            CStudent::SetInfo(name_, id_, age_, gender_);   //调用基类的SetInfo
            department = department_;
        }
};      //派生的写法是:类名：public 基类名

class CGraduatedStudent:public CStudent{
    private:
        int nDepartment;
        char szMentorName[20];
    
    public:
        int CountSalary(){};
};

int main()
{
    CUndergraduateStudent s2;
    s2.SetInfo("Edward", "35373059", 19, 'M', "Computer Science");
    cout << s2.GetName() << " ";
    s2.QualifiledForBaoyan();
    s2.PrintInfo();
    return 0;
};