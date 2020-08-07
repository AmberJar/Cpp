#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

const int Warrior_Num = 5;

class Headquarter;
class Warrior{
    private:
        Headquarter *pHeadquarter;
        int KindNo;
        int Number;
    
    public:
        static string names[Warrior_Num];
        static int inital_life[Warrior_Num];
        Warrior(Headquarter *p, int no_, int KindNo_);
        void PrintResult(int Time);
};

class Headquarter{
    private:
        int totalLifeValue;
        bool stopped;
        int totalWarriorNum;
        int color;
        int SeqIdx;
        int warriorNum[Warrior_Num];

        Warrior *pWarriors[1000];

    public:
        friend class Warrior;
        static int makingSeq[2][Warrior_Num]; //士兵制作的序列
        string GetColor();
};


void Warrior::PrintResult(int Time){
    string color = pHeadquarter->GetColor();
} 


class Headquarter{
    
};

string GetColor(){
    if (color == 0)
    {
        return "red";
    }
    else
    {
        return "blue";
    }
    
}


string Warrior::names[Warrior_Num] = { "dragon","ninja","iceman","lion","wolf" };
int Warrior::initial_life[Warrior_Num];
int Headquarter::makingSeq[2][Warrior_Num] = { { 2,3,4,1,0 },{ 3,0,1,2,4 } }; //两个司令部武士的制作顺序序列  
 
int main()
{
    int t;  //number of tests
    int n;  //case number
    int m;  //life

    cin >> t;
    int CaseNo = 1;

    while (t--)
    {
        cout << "Case: " << t << endl;
        CaseNo ++;
        Headquarter Redhead, Bulehead;
        cin >> m;

        for (int i = 0; i < Warrior_Num; i++)
            cin >> Warrior::initial_life[i];

        int Time = 0;
        while (true)
        {
            int tmp1;
            int tmp2;

            tmp1 = Redhead;
            tmp2 = Bulehead;

            if (tmp1 == 0 && tmp2 == 0)
            {
                break;
            }
            
            Time++;
        }
        
        

    }
    

}