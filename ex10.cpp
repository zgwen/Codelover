#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	unsigned char str[100];
	unsigned char count[128] = {0};
	int n;
	int i;
	int len;
	cin>>str;
	len = strlen((char *)str);
	n = 0;
	for(i=0;i<len;i++)
	{
		if(str[i] >=0 && str[i]<128 && count[str[i]]==0) 
		{
			count[str[i]]++;
			n++;
		}
			
	}
	cout<<n<<endl;
}
