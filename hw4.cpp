/*
题目描述
?连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组； 
?长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。 
输入描述:
连续输入字符串(输入2次,每个字符串长度小于100)
输出描述:
输出到长度为8的新字符串数组
*/

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char s[100];
    char len;
    char i,j,grp,two=2;
    
    while(two--)
    {
        cin>>s;
        len = strlen(s);
        if(len<8)
        {
            *(s+8) = '\0';
            for(i=len;i<8;i++)
            {
                *(s+i) = '0';
            }
            cout<<s<<endl;
        }
        else if(len == 8)
        {
            cout<<s<<endl;
        }
        else
        {
            grp = len/8;
            for(i=0;i<grp;i++)
            {
                for(j=0;j<8;j++)
                {
                    cout<<s[i*8+j];
                    if(j==7)
                        cout<<endl;
                }  
            }
            if((j = len%8) !=0)
            {
                for(i=0;i<j;i++)
                {
                    cout<<s[8*grp+i];
                }
                for(i=0;i<(8-j);i++)
                {
                    cout<<'0';
                    if(i==(8-j-1))
                        cout<<endl;
                }
            }
        }
    }
        
    return 0;
}
