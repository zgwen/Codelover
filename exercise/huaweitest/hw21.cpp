/*
��Ŀ����
���������������зǳ���Ҫ�Ķ��������ǵ���ôһ�㲻��˵�����ܾ�ȫ�����ˡ�
�۹���. ������Ԩ��Ҫ������֮���ټ�һ�����룬��Ȼ�򵥵�Ҳ��ȫ��
����Ԩ��ԭ��һ��BBS�ϵ�����Ϊzvbo9441987,Ϊ�˷�����䣬
��ͨ��һ���㷨���������任��YUANzhi1987������������������ֺͳ�����ݣ�
��ô���������ˣ����ҿ�����Ŀ�ŵ��ط������۵ĵط�����������֪�����������롣
������ô�任�ģ���Ҷ�֪���ֻ��ϵ���ĸ�� 
1--1�� abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0,
����ô�򵥣�Ԩ�Ӱ������г��ֵ�Сд��ĸ����ɶ�Ӧ�����֣����ֺ������ķ��Ŷ������任��
������������û�пո񣬶������г��ֵĴ�д��ĸ����Сд֮��������һλ���磺
X���ȱ��Сд����������һλ��������y����򵥰ɡ���ס��z��������aŶ��
��������:
�����������������ݡ�������һ�����ģ����볤�Ȳ�����100���ַ�������ֱ���ļ���β
�������:
���Ԩ������������
ʾ��1
����
YUANzhi1987
���
zvbo9441987
*/ 

#include <iostream>
#include <string.h>
using namespace std;

char lower2num(char c)
{
	if((c >= 'w') && (c <= 'z')) return '9';
	else if((c >= 'p') && (c <= 's')) return '7';
	else if((c >= 'a') && (c <= 'c')) return '2';
	else if((c >= 'd') && (c <= 'f')) return '3';
	else if((c >= 'g') && (c <= 'i')) return '4';
	else if((c >= 'j') && (c <= 'l')) return '5';
	else if((c >= 'm') && (c <= 'o')) return '6';
	else if((c >= 't') && (c <= 'v')) return '8';	
	return 0;
}

int main()
{
	char str[100];
	char passwd[100];
	char c;
	int i;
	while(cin >> str){
		int len = strlen(str);
		for(i = 0; i < len; i++){
			c = str[i];
			if((c >= '0') && (c <= '9')){
				passwd[i] = c;
			}
			else if((c >= 'A') && (c <= 'Z')){
				if(c == 'Z') passwd[i] = 'a';
				else passwd[i] = c-'A'+'a'+1;	
			}
			else if((c >= 'a') && (c <= 'z')){
				passwd[i] = lower2num(c);
			}
		}
		passwd[i] = '\0';
		cout << passwd << endl;
	}	
}
