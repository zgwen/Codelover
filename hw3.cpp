/*
��Ŀ����
��������ѧУ����һЩͬѧһ����һ���ʾ����飬Ϊ��ʵ��Ŀ͹��ԣ������ü����������N��1��1000֮������������N��1000�������������ظ������֣�ֻ����һ������������ͬ����ȥ������ͬ������Ӧ�Ų�ͬ��ѧ����ѧ�š�Ȼ���ٰ���Щ����С�������򣬰����źõ�˳��ȥ��ͬѧ�����顣����Э��������ɡ�ȥ�ء��롰���򡱵Ĺ���(ͬһ��������������ܻ��ж������ݣ�ϣ���������ȷ����)��


Input Param
n               ����������ĸ���
inputArray      n�����������ɵ�����

Return Value
OutputArray    �����������������


ע������������֤�����������ȷ�ԣ�������������֤������������ֹһ�顣


��������:
������У���������������ĸ�������������Ӧ����������
�������:
���ض��У�������Ľ��
*/
#include<iostream>
#include<memory.h>
using namespace std;
int main()
{
    int i=0,count=0;
    int num[1000];
    int nflag[1001]={-1};
   
    loop:
    memset(nflag,-1,sizeof(nflag));
    cin>>count;
    for(i=0;i<count;i++)
    {
        if(cin>>num[i])
            nflag[num[i]]=1;
        else
            return 0;
    }
    for(i=0;i<1001;i++)
    {
        if(nflag[i]==1)
            cout<<i<<endl;
    }
    goto loop;
}