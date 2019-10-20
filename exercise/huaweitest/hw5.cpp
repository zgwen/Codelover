/*
进制转换
题目描述
写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
输入描述:
输入一个十六进制的数值字符串。
输出描述:
输出该数值的十进制字符串。
*/ 

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int num;
    while(cin>>s)
    {
        num = 0;
        for(auto &c : s.substr(2,s.size()))
        {
            c = toupper(c);
            if((c>='A') && (c<='F'))
                c = c -'A'+ 10;
            else
                c = c - '0';
            num = num*16 + c;
        }
        cout << num <<endl;

    }
    return 0;
}
