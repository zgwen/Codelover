/*
合并表记录
题目描述
数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
输入描述:
先输入键值对的个数
然后输入成对的index和value值，以空格隔开
输出描述:
输出合并后的键值对（多行）
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
