/*
密码验证合格程序 
题目描述
密码要求:
1.长度超过8位
2.包括大小写字母.数字.其它符号,以上四种至少三种
3.不能有相同长度超2的子串重复
说明:长度超过2的子串
输入描述:
一组或多组长度超过2的子符串。每组占一行
输出描述:
如果符合要求输出：OK，否则输出NG
 */

#include <iostream>
#include <string.h>

using namespace std;
/*字符种类统计*/ 
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
			/*比较长度超过2的字符串*/
			for(j=i+1;j<len-2;j++){
				if((str[j]   == str[i])   && \
				   (str[j+1] == str[i+1]) && \
				   (str[j+2] == str[i+2]))
				  goto NG;
			}	
			/*统计每类字符*/ 
			char_count(str[i], count);
		}
		/*统计不存在的字符种类*/
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
