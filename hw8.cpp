/*
取近似值
写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
输入描述:
输入一个正浮点数值
输出描述:
输出该数值的近似整数值
*/
# include<iostream>
#include<memory.h>

using namespace std;

int main()
{
	int count;
	int index,value;
	int num[1000];
	memset(num,0,sizeof(num));
	cin >> count;
	while(count--)
	{
		cin >> index >> value;
		num[index] += value;
	}
	count = sizeof(num)/4;
	index = 0;
	while(index < count)
	{
		if(num[index] != 0)
			cout<<(index)<<' '<<num[index]<<endl;
		index++;
	}
	return 0;
}
