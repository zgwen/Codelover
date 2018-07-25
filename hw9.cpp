#include<iostream>
#include<memory.h>
#include<string.h>
using namespace std;

int main()
{
	char str[100];
	int num[10];
	int i,len;
	memset(num,0,sizeof(num));
	cin>>str;
	len = strlen(str);
	for(i=len;i>0;i--)
	{
		if(num[str[i-1] - '0'] == 0)
		{
			cout<<str[i-1];
			num[str[i-1] - '0']++;
		}
	}
	cout<<endl;
	
	
}
