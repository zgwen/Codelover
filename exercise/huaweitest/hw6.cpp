/*
质数因子
功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
最后一个数后面也要有空格
详细描述：
函数接口说明：
public String getResult(long ulDataInput)
输入参数：
long ulDataInput：输入的正整数
返回值：
String
输入描述:
输入一个long型整数
输出描述:
按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。
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
