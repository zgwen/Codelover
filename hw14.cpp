/*
字串的连接最长路径查找
题目描述
给定n个字符串，请对n个字符串按照字典序排列。
输入描述:
输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
输出描述:
数据输出n行，输出结果为按照字典序排列的字符串。
*/ 
#include<iostream>
#include<memory.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct wrd {
	char str[100];
};
void bubble(struct wrd *words,int len)
{
	char c1,c2;
	char temp[100];
	for(int i=0;i<len-1;i++)
		{
			for(int j=0;j<len-1-i;j++)
			{
				if(strcmp(words[j].str,words[j+1].str)>=0)
				{
					strcpy(temp,words[j].str);
					strcpy(words[j].str,words[j+1].str);
					strcpy(words[j+1].str,temp);
				}
			}		
		}
}

int main()
{
	int n;
	cin >> n;
	struct wrd *words;
	words = (struct wrd *)malloc(sizeof(struct wrd)*n);
	for(int i=0;i<n;i++) 
	{
		cin >> words[i].str;	
	}
	bubble(words,n);
	for(int i=0;i<n;i++) 
		cout << words[i].str<< endl;
	return 0;
		
	
}
