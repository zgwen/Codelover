/*
��������
��Ŀ����
��һ��Ӣ������Ե���Ϊ��λ�����ŷš����硰I am a boy���������ŷź�Ϊ��boy a am I��
���е���֮����һ���ո����������г���Ӣ����ĸ�⣬���ٰ��������ַ�
��������:
��һ��Ӣ������Ե���Ϊ��λ�����ŷš�
�������:
�õ�����ľ���
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
