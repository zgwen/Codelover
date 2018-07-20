#include <iostream>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    int len1=a.length();
    int len2=b.length();
    string c(100,0);	//或者是 char c[100] 
    int i,j,k=0;
    int temp;
	for(i=len2-1,j=len1-1;i>=0 && j>=0;i--,j--)
	{
		if((k+1)%2 != 0)//奇数位
		{
			temp = (a[j]-'0'+b[i]-'0')%13;
			if(temp == 10) c[k] = 'J';
			else if(temp == 11) c[k] = 'Q';
			else if(temp == 12) c[k] = 'K';
			else c[k] = temp + '0';
		} 
		else
		{
			temp = 	b[i]-a[j];
			temp = (temp>=0) ? temp : (temp+10);
			c[k] = temp + '0';
		}
		k++;
		 
	}
	for(;i>=0;i--)
	{
		c[k++] = b[i];
	}
	for(;j>=0;j--)
	{
		if((k+1)%2 != 0)//奇数位 
		{
			c[k++] = a[j];
		}
		else
		{
			c[k++] = (a[j]=='0') ?  '0' : (10-(a[j]-'0')+'0');
		}
	}
	for(;k>0;k--)
		cout << c[k-1];
	cout << endl;
    return 0;
}
