/*
��Ŀ����
����һ��������㹤�ߣ� A��ʾ�����ƶ���D��ʾ�����ƶ���W��ʾ�����ƶ���S��ʾ�����ƶ���
�ӣ�0,0���㿪ʼ�ƶ����������ַ��������ȡһЩ���꣬�����������������������ļ����档
���룺
�Ϸ�����ΪA(����D����W����S) + ���֣���λ���ڣ�
����֮����;�ָ���
�Ƿ��������Ҫ���ж�������AA10;  A1A;  $%$;  YAD; �ȡ�
������һ���򵥵����� �磺
A10;S20;W10;D30;X;A1A;B10A11;;A10;
������̣�
��㣨0,0��
+   A10   =  ��-10,0��
+   S20   =  (-10,-20)
+   W10  =  (-10,-10)
+   D30  =  (20,-10)
+   x    =  ��Ч
+   A1A   =  ��Ч
+   B10A11   =  ��Ч
+  һ���� ��Ӱ��
+   A10  =  (10,-10)

��� ��10�� -10��
��������:
һ���ַ���
�������:
�������꣬��,�ָ�
*/

/*������������һ��whileѭ���ж��룬�Ǹ���ӣ�*/
#include <iostream>
using namespace std;

int main()
{
	char str[10000];
	while(cin >> str)
	{
		int len=0,pos,num;
		int x=0,y=0;
		int i,j;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i] == ';')
			{
				pos = i-len;
				if( str[pos] != 'A' && \
					str[pos] != 'D' && \
					str[pos] != 'W' && \
					str[pos] != 'S' )
				{
					len = 0;
					continue;
				}
				num = 0;
				for(j=pos+1;j<i;j++)
				{
					if(str[j]<'0' || str[j]>'9')
					{
						len = 0;
						break;
					}
					num = str[j] - '0' + num*10;
				}
				if(j!=i) continue;
				switch(str[pos])
				{
					case 'A': x-=num;break;
					case 'D': x+=num;break;
					case 'W': y+=num;break;
					case 'S': y-=num;
					default: break;
				}
				len = 0;
			}	
			else 
				len++;
			
		}
		cout << x << "," << y << endl;
	}
	return 0;
} 
