/*
句子逆序
题目描述
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
输入描述:
将一个英文语句以单词为单位逆序排放。
输出描述:
得到逆序的句子
*/ 
#include<iostream>
#include<string.h>
using namespace std;
void reverse(char *str)
{
	int len = strlen(str);
	int i = len-1;
	for(;i>=0;i--)
	{
		if(str[i] == ' ')
			{
				cout << str+i+1 << ' ';
				str[i] = '\0';
				reverse(str);
				break;
			}
	}
	if(i == -1)
	{
		cout << str;
	}
}
int main()
{
	char sentence[1000];
	cin.getline(sentence,sizeof(sentence));
	reverse(sentence); 
	return 0;
}
