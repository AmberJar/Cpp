#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>  //reverse函数所需添加的头文件
using namespace std;

class BigInt
{
    private:
        string values;  //保存所有位上的数字
        bool flag;      //true表示正数，false表示负数，0默认为正数

        inline int compare(string s1, string s2){
            if (s1.size() < s2.size())
                return -1;
            else if (s1.size() > s2.size())
                return 1;
            else
                return s1.compare(s2);  //http://www.cplusplus.com/reference/string/string/compare/
        }

    public:
        BigInt() :values("0"), flag(true){};
        BigInt(string str)  //类型转换构造函数(默认为正整数)
        {
            values = str;
            flag = true;
        }
    public:
        friend ostream& operator << (ostream& os, const BigInt& bigInt);  //重载输出操作符
        friend istream& operator>>(istream& is, BigInt& bigInt);  //输入操作符重载
        BigInt operator+(const BigInt& rhs);  //加法操作重载
        BigInt operator-(const BigInt& rhs);  //减法操作重载
        BigInt operator*(const BigInt& rhs);  //乘法操作重载
        BigInt operator/(const BigInt& rhs);  //除法操作重载
};

//重载流提取运算符'<<'，输出一个整数****************************************************************
ostream& operator << (ostream& os, const BigInt& bigInt){
    if (!bigInt.flag){
        os << '-';
    }
    os << bigInt.values;
    return os;
}

//重载流插入运算符'>>'，输入一个正整数***************************************************************
istream& operator >> (istream& is, BigInt& bigInt){
    string str;
    is >> str;
    bigInt.values = str;
    bigInt.flag = true;
    return is;
}

//加法操作重载***************************************************************************************
//具体思路就是模仿手算的加法
BigInt BigInt::operator+(const BigInt& rhs){
    BigInt ret;                                   //ret: result
    ret.flag = true;  //正整数相加恒为正数
    string lvalues(values), rvalues(rhs.values);  //lvalues: left values, rvalues: right values
    //处理特殊情况                                 //是在values所在的类中调用的 + 号，然后在以引用的形式调用rvalues,即rhs.values
    if (lvalues == "0"){
        ret.values = rvalues;
        return ret;
    }
    if (rvalues == "0"){
        ret.values = lvalues;
        return ret;
    }
    //调整s1与s2的长度
    unsigned int i, lsize, rsize;
    lsize = lvalues.size();
    rsize = rvalues.size();
    if (lsize < rsize){
        for (i = 0; i < rsize - lsize; i++)  //在lvalues左边补零
        {
            lvalues = "0" + lvalues;
        }
    }
    else
    {
        for (i = 0; i < lsize - rsize; i++)  //在rvalues左边补零
        {
            rvalues = "0" + rvalues;
        }
    }
    //处理本质情况
    int n1, n2;
    n2 = 0;
    lsize = lvalues.size();
    string res = "";
    reverse(lvalues.begin(), lvalues.end());  //颠倒字符串，以方便从低位算起计算
    reverse(rvalues.begin(), rvalues.end());
    for (i = 0; i < lsize; i++){
        n1 = ((lvalues[i] - '0') + (rvalues[i] - '0') + n2) % 10;  //n1代表当前位的值；lvalues[i] 和 '0' 都是 char 型，可以作差得到 int 型
        //n1 = (lvalues[i] - '0' + rvalues[i] - '0' + n2) % 10; 这样也可以，但不直观
        n2 = ((lvalues[i] - '0') + (rvalues[i] - '0') + n2) / 10;  //n2代表进位
        res = res + char(n1 + '0');
    }

    if (n2 == 1){
        res = res + "1";
    }
    reverse(res.begin(), res.end());

    ret.values = res;
    return ret;
}

//减法操作重载***************************************************************************************
//同样是模拟手算
BigInt BigInt::operator-(const BigInt& rhs)
{
    BigInt ret;
    string lvalues(values), rvalues(rhs.values);
    //处理特殊情况
    if (rvalues == "0"){
        ret.values = lvalues;
        ret.flag = true;                     //此时作差定为正数
        return ret;
    }
    if (lvalues == "0"){
        ret.values = rvalues;
        ret.flag = false;                    //此时作差定为负数
        return ret;
    }
    //调整s1与s2的长度
    unsigned int i, lsize, rsize;
    lsize = lvalues.size();
    rsize = rvalues.size();
    if (lsize < rsize){
        for (i = 0; i < rsize - lsize; i++)  //在lvalues左边补零
        {
            lvalues = "0" + lvalues;
        }
    }
    else
    {
        for (i = 0; i < lsize - rsize; i++)  //在rvalues左边补零
        {
            rvalues = "0" + rvalues;
        }
    }
    //调整使‘-’号前边的数大于后边的数
    int t = lvalues.compare(rvalues);  //相等返回0，str1<str2返回负数，str1>str2返回正数
    if (t < 0)                         //比较规则：对两个字符串自左至右逐个字符按ASCII码值比较
    {
        ret.flag = false;              //此时作差定为负数
        string tmp = lvalues;          //lvalues 与 rvalues 调换
        lvalues = rvalues;
        rvalues = tmp;
    }
    else if (t == 0)
    {
        ret.values = "0";
        ret.flag = true;
        return ret;
    }
    else
    {
        ret.flag = true;
    }
    //处理本质情况
    unsigned int j;
    lsize = lvalues.size();
    string res = "";
    reverse(lvalues.begin(), lvalues.end());   //颠倒字符串，以方便从低位算起计算
    reverse(rvalues.begin(), rvalues.end());
    for (i = 0; i < lsize; i++){
        if (lvalues[i] < rvalues[i])           //不足，向前借一位
        {
            j = 1;
            while (lvalues[i + j] == '0'){
                lvalues[i + j] = '9';
                j++;
            }
            lvalues[i + j] -= 1;
            res = res + char(lvalues[i] + ':' - rvalues[i]);
        }
        else{
            res = res + char(lvalues[i] - rvalues[i] + '0');
        }
    }
    reverse(res.begin(), res.end());
    res.erase(0, res.find_first_not_of('0'));  //去掉前导零

    ret.values = res;
    return ret;
}

//乘法操作重载***************************************************************************************
//模拟手算
BigInt BigInt::operator*(const BigInt& rhs){
    BigInt ret;
    string lvalues(values), rvalues(rhs.values);
    //处理特殊情况
    if (lvalues == "0" || rvalues == "0"){
        ret.values = "0";
        ret.flag = true;
        return ret;
    }

    unsigned int lsize, rsize;
    lsize = lvalues.size();
    rsize = rvalues.size();
    string temp;
    BigInt res, itemp;
    //让lvalues的长度最长
    if (lvalues < rvalues){
        temp = lvalues;
        lvalues = rvalues;
        rvalues = temp;
        lsize = lvalues.size();
        rsize = rvalues.size();
    }
    //处理本质情况
    int i, j, n1, n2;
    reverse(lvalues.begin(), lvalues.end());  //颠倒字符串
    reverse(rvalues.begin(), rvalues.end());
    for (i = 0; i < rsize; i++){
        temp = "";      //注意temp每次要置回空串！！！！！！
        n1 = n2 = 0;    //n1,n2也要置回0！！！！！！

        for (j = 0; j < lsize; j++){
            n1 = ((lvalues[j] - '0')*(rvalues[i] - '0') + n2) % 10;  //n1记录当前位置的值
            n2 = ((lvalues[j] - '0')*(rvalues[i] - '0') + n2) / 10;  //n2记录进位的值
            temp = temp + char(n1 + '0');
        }
        if (n2){
            temp = temp + char(n2 + '0');
        }
        reverse(temp.begin(), temp.end());
        for (j = 0; j < i; j++){
            temp = temp + "0";
        }
        itemp.values = temp;
        res = res + itemp;  //类和类相加才会调用 + 号重载操作符！！！！！！
    }

    ret = res;
    return ret;
}

//除法操作重载***************************************************************************************
BigInt BigInt::operator/(const BigInt& rhs){
    BigInt ret;
    string lvalues(values), rvalues(rhs.values);
    string quotient;
    //处理特殊情况
    if (rvalues == "0"){
        ret.values = "error";//输出错误
        ret.flag = true;
        return ret;
    }
    if (lvalues == "0"){
        ret.values = "0";
        ret.flag = true;
        return ret;
    }

    if (compare(lvalues, rvalues) < 0){
        ret.values = "0";
        ret.flag = true;
        return ret;
    }
    else if (compare(lvalues, rvalues) == 0){
        ret.values = "1";
        ret.flag = true;
        return ret;
    }
    else{
        //处理本质情况
        string temp;
        unsigned int lsize, rsize;
        lsize = lvalues.size();
        rsize = rvalues.size();
        int i;
        if (rsize > 1) temp.append(lvalues, 0, rsize - 1);
        for (i = rsize - 1; i < lsize; i++){
            temp = temp + lvalues[i];
            //试商
            for (char c = '9'; c >= '0'; c--){
                BigInt t = (BigInt)rvalues * (BigInt)string(1, c);  //string( size_type length, char ch ); 以length为长度的ch的拷贝（即length个ch） 
                BigInt s = (BigInt)temp - t;

                if (s.flag == true){
                    temp = s.values;
                    quotient = quotient + c;
                    break;
                }
            }
        }
    }
    //去除前导零
    quotient.erase(0, quotient.find_first_not_of('0'));  //http://www.cplusplus.com/reference/string/string/find_first_not_of/?kw=string%3A%3Afind_first_not_of
    ret.values = quotient;                               //string::erase http://www.cplusplus.com/reference/string/string/erase/?kw=string%3A%3Aerase
    ret.flag = true;
    return ret;
}

int main()
{
    BigInt a, b, result;
    char op;
    cin >> a >> op >> b;
    switch (op)
    {
    case '+':result = a + b; break;
    case '-':result = a - b; break;
    case '*':result = a * b; break;
    case '/':result = a / b; break;
    default:break;
    }
    cout << result << endl;
    return 0;
}

/*
测试数据：
1.741269586512*984562478654

2.48789151687984156*56487112346786

3.56765156165465786156467/54657815454782

4.8465156478654165468421-15646878115487854312234567

5.48951487894146576543215646+5123123165784512313215686

6.87894123467984512789/5684

答案如下:
1.729826221447080406314848

2.2755958292703544831466745522616

3.1038555157

4.-15638412959009200146766146

5.54074611059931088856431332

6.15463427774100019
*/