/*
字符个数统计
题目描述
编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
输入描述:
输入N个字符，字符在ACSII码范围内。
输出描述:
输出范围在(0~127)字符的个数。
*/

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	unsigned char str[100];
	unsigned char count[128] = {0};
	int n;
	int i;
	int len;
	cin>>str;
	len = strlen((char *)str);
	n = 0;
	for(i=0;i<len;i++)
	{
		if(str[i] >=0 && str[i]<128 && count[str[i]]==0) 
		{
			count[str[i]]++;
			n++;
		}
			
	}
	cout<<n<<endl;
}
