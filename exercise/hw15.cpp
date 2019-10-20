/*
求int型正整数在内存中存储时1的个数
题目描述
输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。
输入描述:
 输入一个整数（int类型）
输出描述:
 这个数转换成2进制后，输出1的个数
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
