/**
*���ļ��������ڲ���һЩ�뷨
*�Ͼ�����һ�������뷨�������� 
*/ 


/*��ά���麯�����ݲ���*/ 

#include <iostream>
#include <process.h>
using namespace std;

void testp(int data[][3])     
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cout << data[i][j]<<' ';
	
}
 

int main()
{
	int data[3][3];
	cout << "����Ÿ���:" << endl;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin >> data[i][j];
	cout << "���:" << endl;
	testp(data);
	system("pause"); 
 } 
