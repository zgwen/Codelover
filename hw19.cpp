/*
��Ŀ����
����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
���� 
1�� ��¼���8�������¼��ѭ����¼������ͬ�Ĵ����¼�����ļ����ƺ��к���ȫƥ�䣩ֻ��¼һ��������������ӣ�
2�� ����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���
3�� ������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·����
��������:
һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������
�������:
�����еļ�¼ͳ�Ʋ�������������ʽ���ļ��� �������� ��Ŀ��һ���ո�������磺
ʾ��1
����
E:\V1R2\product\fpgadrive.c   1325
���
fpgadrive.c 1325 1
*/

/*
���⼫�ӣ�����¼���8�������¼����ȫ�Ǻ����˵ģ������ں�̨Ӧ�ð����м�¼ȫ����¼������ֻ�������������
 
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

struct err_log {
	char name[17];
	int line;
	int cnt;
};

int main()
{
	char str[1000];
	char temp_name[17];
	int temp_line;
	int len;
	int i,loop;
	struct err_log log[100]={
		0,0
	}; 
	loop = 0;
	while(cin >> str >> temp_line)
	{
		
		len = strlen(str);
		//��ȡ��󳤶�Ϊ16���ļ��� 
		for(i=len-1;str[i] != '\\';i--);
		if((len - i) > 16)
			strcpy(temp_name,str+len-16);
		else 
			strcpy(temp_name,str+i+1);
		//�Ƚ��ļ������кţ������ͬ����ϲ�
		for(i=0;i<loop;i++)
		{
			if((log[i].line == temp_line) && (!strcmp(temp_name,log[i].name)))
			{
				log[i].cnt++;break;
			}
		}
		//���û�ҵ���ͬ�ģ����ں�������һ�� 
		if(i==loop)
		{
			strcpy(log[loop].name,temp_name);
			log[loop].line = temp_line;
			log[loop].cnt = 1;
			loop = loop+1;
		}
		
		
	}
	//��ӡ��������¼���������ڰ�������� 
	len = (loop > 8)?8:(loop);
	for(i=loop-len;i<loop;i++)
	{
		if(log[i].cnt != 0)
			cout << log[i].name << ' ' << log[i].line << ' ' << log[i].cnt << endl;
	}
		
	
}
