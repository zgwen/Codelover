/*
������֤�ϸ���� 
��Ŀ����
����Ҫ��:
1.���ȳ���8λ
2.������Сд��ĸ.����.��������,����������������
3.��������ͬ���ȳ�2���Ӵ��ظ�
˵��:���ȳ���2���Ӵ�
��������:
һ�����鳤�ȳ���2���ӷ�����ÿ��ռһ��
�������:
�������Ҫ�������OK���������NG
 */

#include <iostream>
#include <string.h>

using namespace std;
/*�ַ�����ͳ��*/ 
void char_count(char c, int *count)
{
	if((c >= 'A') && (c <= 'Z')){
		*(count) = 1;
		return;
	}
	if((c >= 'a') && (c <= 'z')){
		*(count+1) = 1;
		return;
	}
	if((c >= '0') && (c <= '9')){
		*(count+2) = 1;
		return;
	}
	*(count+3) = 1;
}

int main()
{
	char str[1000];
	while(cin >> str){
		int len,i,j;
		int count[4] = {0};
		len = strlen(str);
		if(len <= 8) goto NG;
		for(i = 0; i < len; i++){
			/*�Ƚϳ��ȳ���2���ַ���*/
			for(j=i+1;j<len-2;j++){
				if((str[j]   == str[i])   && \
				   (str[j+1] == str[i+1]) && \
				   (str[j+2] == str[i+2]))
				  goto NG;
			}	
			/*ͳ��ÿ���ַ�*/ 
			char_count(str[i], count);
		}
		/*ͳ�Ʋ����ڵ��ַ�����*/
		len = 0;
		for(i = 0; i < 4; i++)
		{
			if(count[i] == 0) len++;
		}
		if(len > 1) goto NG;
		
OK:		cout << "OK" << endl;
		continue;
NG:		cout << "NG" << endl;			
	}
}
