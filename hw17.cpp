/*
题目描述
开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。
从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。
输入：
合法坐标为A(或者D或者W或者S) + 数字（两位以内）
坐标之间以;分隔。
非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。
下面是一个简单的例子 如：
A10;S20;W10;D30;X;A1A;B10A11;;A10;
处理过程：
起点（0,0）
+   A10   =  （-10,0）
+   S20   =  (-10,-20)
+   W10  =  (-10,-10)
+   D30  =  (20,-10)
+   x    =  无效
+   A1A   =  无效
+   B10A11   =  无效
+  一个空 不影响
+   A10  =  (10,-10)

结果 （10， -10）
输入描述:
一行字符串
输出描述:
最终坐标，以,分隔
*/

/*测试用例是在一个while循环中读入，是个大坑！*/
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
