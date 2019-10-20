/*
1048 数字加密(20)（20 分）

本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。
输入格式：
输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。
输出格式：
在一行中输出加密后的结果。
输入样例：
1234567 368782971
输出样例：
3695Q8118
*/ 
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
