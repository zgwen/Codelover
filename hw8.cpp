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
