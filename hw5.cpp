/*
����ת��
��Ŀ����
д��һ�����򣬽���һ��ʮ�����Ƶ���ֵ�ַ������������ֵ��ʮ�����ַ�����������ͬʱ���� ��
��������:
����һ��ʮ�����Ƶ���ֵ�ַ�����
�������:
�������ֵ��ʮ�����ַ�����
*/ 

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int num;
    while(cin>>s)
    {
        num = 0;
        for(auto &c : s.substr(2,s.size()))
        {
            c = toupper(c);
            if((c>='A') && (c<='F'))
                c = c -'A'+ 10;
            else
                c = c - '0';
            num = num*16 + c;
        }
        cout << num <<endl;

    }
    return 0;
}
