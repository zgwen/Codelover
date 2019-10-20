/*
题目描述
请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。
所有的IP地址划分为 A,B,C,D,E五类
A类地址1.0.0.0~126.255.255.255;
B类地址128.0.0.0~191.255.255.255;
C类地址192.0.0.0~223.255.255.255;
D类地址224.0.0.0~239.255.255.255；
E类地址240.0.0.0~255.255.255.255

私网IP范围是：
10.0.0.0～10.255.255.255
172.16.0.0～172.31.255.255
192.168.0.0～192.168.255.255

子网掩码为前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
本题暂时默认以0开头的IP地址是合法的，比如0.1.1.2，是合法地址
输入描述:
多行字符串。每行一个IP地址和掩码，用~隔开。
输出描述:
统计A、B、C、D、E、错误IP地址或错误掩码、私有IP的个数，之间以空格隔开
*/ 

#include <iostream>
#include <stdio.h> 
#include <stdint.h>
using namespace std;

#define A1 (1<<24)
#define A2 ((126<<24) | (255<<16) | (255<<8) | (255<<0))
#define B1 (128<<24)
#define B2 ((191<<24) | (255<<16) | (255<<8) | (255<<0))
#define C1 (192<<24)
#define C2 ((223<<24) | (255<<16) | (255<<8) | (255<<0))
#define D1 (224<<24)
#define D2 ((239<<24) | (255<<16) | (255<<8) | (255<<0))
#define E1 (240<<24)
#define E2 ((255<<24) | (255<<16) | (255<<8) | (255<<0))

#define P1 (10<<24)
#define P2 ((10<<24) | (255<<16) | (255<<8) | (255<<0))
#define P3 ((172<<24)| (16 <<16))
#define P4 ((172<<24)| (31 <<16) | (255<<8) | (255<<0))
#define P5 ((192<<24)| (168<<16))
#define P6 ((192<<24)| (168<<16) | (255<<8) | (255<<0))

struct ip_count{
	int a,b,c,d,e;
	int err;
	int prv;
};
int main()
{
	uint32_t ip_addr,net_mask;
	uint32_t ip[4]={0},mask[4]={0};
	int i,j,ret,oz_flag;
	char str[100];
	struct ip_count cnt = {
		0,0,0,0,0,0,0
	};
	while((cin>>str))
	{
		
		//尝试读取数值，如果读取到的数值不够八个，说明格式有误 
		ret = sscanf(str,"%d.%d.%d.%d~%d.%d.%d.%d",ip,ip+1,ip+2,ip+3,mask,mask+1,mask+2,mask+3);
		if(ret != 8)
		{
			cnt.err++;
			continue;
		}
		//开始检测掩码的错误，255.255.255.255也是错误的 
		net_mask = (mask[0]<<24)|(mask[1]<<16)|(mask[2]<<8)|(mask[3]<<0);
		oz_flag = 1;
		for(i=31;i>=0;i--)
		{
			if(oz_flag == 1)
			{
				if(((net_mask>>i) & 0x01) == 0)	//& 和 == 的优先级问题 
					oz_flag = 0;
			}
			else
			{
				if(((net_mask>>i) & 0x01)== 1)
					{
						oz_flag = -1;
						break;
					}
			}
		}
		if(oz_flag != 0)
		{
			cnt.err++;
			continue;
		}
		//判断ABCDE
		ip_addr = (ip[0]<<24)|(ip[1]<<16)|(ip[2]<<8)|(ip[3]<<0);
		if(ip_addr>=A1 && ip_addr<=A2) cnt.a++;
		else if(ip_addr>=B1 && ip_addr<=B2) cnt.b++;
		else if(ip_addr>=C1 && ip_addr<=C2) cnt.c++;
		else if(ip_addr>=D1 && ip_addr<=D2) cnt.d++;
		else if(ip_addr>=E1 && ip_addr<=E2) cnt.e++;
		//else
		//{
		//	cnt.err++;
		//	continue;
		//}
		//判断私网ip
		if(	(ip_addr>=P1 && ip_addr<=P2) || \
			(ip_addr>=P3 && ip_addr<=P4) || \
			(ip_addr>=P5 && ip_addr<=P6) )
			cnt.prv++;		
	}
	cout << cnt.a << ' ' << cnt.b << ' ' << cnt.c << ' ' \
		<< cnt.d << ' ' << cnt.e << ' ' << cnt.err << ' ' \
		<< cnt.prv << endl;

	return 0;
}
