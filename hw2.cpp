/*
�����ַ�����
��Ŀ����
д��һ�����򣬽���һ������ĸ��������ɵ��ַ�������һ���ַ���Ȼ����������ַ����к��и��ַ��ĸ����������ִ�Сд��
��������:
����һ������ĸ�������Լ��ո���ɵ��ַ�������һ���ַ���
�������:
��������ַ����к��и��ַ��ĸ�����
*/

#include<iostream>
#include<string.h>
using namespace std;
#define ARRAY_SIZE 500
int main()
{
    char s[ARRAY_SIZE];
    char c[2];
    int size = 0;
    int i,num = 0;
    if(cin.getline(s,ARRAY_SIZE))
        size = strlen(s);
    cin>>c[0];
    if((c[0]>= 'a') && (c[0]<='z'))
        c[1] = c[0] - 'a' + 'A';
    else if((c[0]>= 'A') && (c[0]<='Z'))
        c[1] = c[0] - 'A' + 'a';
    for(i=0;i<size;i++)
    {
        if((s[i]==c[0]) || (s[i] == c[1]))
            num++;
    }
    cout<<num;
    
    return 0;
}
