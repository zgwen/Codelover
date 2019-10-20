/*
计算字符个数
题目描述
写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
输入描述:
输入一个有字母和数字以及空格组成的字符串，和一个字符。
输出描述:
输出输入字符串中含有该字符的个数。
*/

#include<iostream>
#include<string.h>
using namespace std;
#define ARRAY_SIZE 500
int main()
{
    char s[ARRAY_SIZE];
    char c[2];
    int size = 0;
    int i,num = 0;
    if(cin.getline(s,ARRAY_SIZE))
        size = strlen(s);
    cin>>c[0];
    if((c[0]>= 'a') && (c[0]<='z'))
        c[1] = c[0] - 'a' + 'A';
    else if((c[0]>= 'A') && (c[0]<='Z'))
        c[1] = c[0] - 'A' + 'a';
    for(i=0;i<size;i++)
    {
        if((s[i]==c[0]) || (s[i] == c[1]))
            num++;
    }
    cout<<num;
    
    return 0;
}
