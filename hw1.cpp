/*
��Ŀ����
�����ַ������һ�����ʵĳ��ȣ������Կո������ 
��������:
һ���ַ������ǿգ�����С��5000��
�������:
����N�����һ�����ʵĳ��ȡ�
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
