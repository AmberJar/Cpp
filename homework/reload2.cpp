#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class String{
    private:
        char *str;
    
    public:
        String():str(NULL){ } //构造函数，初始化str为NULL
        const char *c_str(){return str;}
        char * operator= (const char *s);
        //不指向同一个内存而是替换原来的内存,就不会出现重复释放内存的问题
        String &operator=(const String &s){
            if(str == s.str) return *this; //复制自身
            if(str) delete[]str;
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
            return * this;
        }
        String::String(String &s)
        {
            if(s.str){
                str = new char[strlen(s.str) + 1];
                strcpy(str, s.str);
            }
            else
            {
                str = NULL;
            }
        }
        ~String();
};

char *String::operator=(const char *s){
    if(str) delete[]str;
    if(s){
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else
    {
        str = NULL;
    }

    return str;
}
String::~String(){
    if(str) delete[]str;
};

int main(){
    String s;
    s = "Good Luck,";
    cout <<s.c_str() << endl;
    //String s2 = "hello!"; //这条语句不注释就会出错
    s = "Shenzhou 8!";
    cout << s.c_str() << endl;
    return 0;
}