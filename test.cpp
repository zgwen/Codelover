/**
*该文件常常用于测试一些想法
*毕竟我是一个很有想法的年轻人 
*/ 


/*二字符串溢出的cpy情形*/ 

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
