/*
�ִ��������·������
��Ŀ����
����n���ַ��������n���ַ��������ֵ������С�
��������:
�����һ��Ϊһ��������n(1��n��1000),����n��Ϊn���ַ���(�ַ������ȡ�100),�ַ�����ֻ���д�Сд��ĸ��
�������:
�������n�У�������Ϊ�����ֵ������е��ַ�����
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
