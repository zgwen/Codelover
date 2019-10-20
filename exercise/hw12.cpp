/*
字符串反转
题目描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
输入描述:
输入N个字符
输出描述:
输出该字符串反转后的字符串
*/
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char a[1000];
	cin >> a;
	for(int i=strlen(a)-1;i >= 0;i--)
		cout << a[i];
	cout << endl;
	return 0;
} 
