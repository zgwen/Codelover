/*
题目描述
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理： 
1、 记录最多8条错误记录，循环记录，对相同的错误记录（净文件名称和行号完全匹配）只记录一条，错误计数增加；
2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
3、 输入的文件可能带路径，记录文件名称不能带路径。
输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
输出描述:
将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：
示例1
输入
E:\V1R2\product\fpgadrive.c   1325
输出
fpgadrive.c 1325 1
*/

/*
此题极坑，“记录最多8条错误记录”完全是忽悠人的，程序在后台应该把所有记录全部记录下来，只是输出八条而已
 
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
		//提取最大长度为16的文件名 
		for(i=len-1;str[i] != '\\';i--);
		if((len - i) > 16)
			strcpy(temp_name,str+len-16);
		else 
			strcpy(temp_name,str+i+1);
		//比较文件名和行号，如果相同，则合并
		for(i=0;i<loop;i++)
		{
			if((log[i].line == temp_line) && (!strcmp(temp_name,log[i].name)))
			{
				log[i].cnt++;break;
			}
		}
		//如果没找到相同的，就在后面增加一个 
		if(i==loop)
		{
			strcpy(log[loop].name,temp_name);
			log[loop].line = temp_line;
			log[loop].cnt = 1;
			loop = loop+1;
		}
		
		
	}
	//打印最多八条记录，考虑少于八条的情况 
	len = (loop > 8)?8:(loop);
	for(i=loop-len;i<loop;i++)
	{
		if(log[i].cnt != 0)
			cout << log[i].name << ' ' << log[i].line << ' ' << log[i].cnt << endl;
	}
		
	
}
