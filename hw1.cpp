/*
题目描述
计算字符串最后一个单词的长度，单词以空格隔开。 
输入描述:
一行字符串，非空，长度小于5000。
输出描述:
整数N，最后一个单词的长度。
*/

#include<stdio.h>
#include<string.h>
int main()
{
    char s[200];
    int i,flag=0;
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==' ')
            flag = i;
    }
    if(flag == 0)
    printf("%d",i-flag);
    else 
        printf("%d",i-flag-1);
    
    return 0;
}
