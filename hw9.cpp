/*
提取不重复的整数
题目描述
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
输入描述:
输入一个int型整数
输出描述:
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
*/

#include<iostream>
#include<memory.h>
#include<string.h>
using namespace std;

int main()
{
	char str[100];
	int num[10];
	int i,len;
	memset(num,0,sizeof(num));
	cin>>str;
	len = strlen(str);
	for(i=len;i>0;i--)
	{
		if(num[str[i-1] - '0'] == 0)
		{
			cout<<str[i-1];
			num[str[i-1] - '0']++;
		}
	}
	cout<<endl;
	
	
}
