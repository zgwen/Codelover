/*
����:����һ�������������մ�С�����˳����������������������ӣ���180����������Ϊ2 2 3 3 5 ��
���һ��������ҲҪ�пո�
��ϸ������
�����ӿ�˵����
public String getResult(long ulDataInput)
���������
long ulDataInput�������������
����ֵ��
String
��������:
����һ��long������
�������:
���մ�С�����˳����������������������ӣ��Կո���������һ��������ҲҪ�пո�
*/
#include<iostream>
using namespace std;

void getResult(long num)
{
	long half = num;
	long i;
	for(i=2;i<=half;i++)
		if(num%i == 0)
			break;
	if(i > half) return;
	cout << i << ' ';
	getResult(num/i);
}

int main()
{
	long num;
	cin >> num;
	getResult(num);
	return 0;
} 
