/*
��int�����������ڴ��д洢ʱ1�ĸ���
��Ŀ����
����һ��int�͵����������������int���������ڴ��д洢ʱ1�ĸ�����
��������:
 ����һ��������int���ͣ�
�������:
 �����ת����2���ƺ����1�ĸ���
*/ 
#include<iostream>
using namespace std;

int main()
{
	int num;
	int temp;
	int count=0;
	cin >> num;
	temp = num;
	while(temp != 0)
	{
		if(temp & 0x01 ==1)
			count++;
		temp = temp/2;
	}
	cout<<count<<endl;
	return 0;
		
	
}
