/**
*���ļ��������ڲ���һЩ�뷨
*�Ͼ�����һ�������뷨�������� 
*/ 


/*���ַ��������cpy����*/ 

#include <iostream>
#include <string.h> 
using namespace std;


int main()
{
	char str1[10];
	char str2[10];
	
	sprintf(str1,"1234567890");
	cout << "str1 len:" << strlen(str1) <<endl;
	strcpy(str2,str1);
	cout << str2;
 } 
