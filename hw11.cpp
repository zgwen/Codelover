/*
��Ŀ����
������
����һ��������������������ַ�������ʽ�������
���򲻿��Ǹ���������������ֺ���0����������ʽҲ����0��������Ϊ100�������Ϊ001
��������:
����һ��int����
�������:
������������ַ�������ʽ�������
*/
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char a[100];
	cin >> a;
	for(int i=strlen(a)-1;i >= 0;i--)
		cout << a[i];
	cout << endl;
	return 0;
} 
