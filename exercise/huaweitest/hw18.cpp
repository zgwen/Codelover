/*
��Ŀ����
�����IP��ַ�Ͷ�Ӧ�����룬���з���ʶ��Ҫ����A/B/C/D/E���ַ���࣬���Ϸ��ĵ�ַ�����뵥�����ࡣ
���е�IP��ַ����Ϊ A,B,C,D,E����
A���ַ1.0.0.0~126.255.255.255;
B���ַ128.0.0.0~191.255.255.255;
C���ַ192.0.0.0~223.255.255.255;
D���ַ224.0.0.0~239.255.255.255��
E���ַ240.0.0.0~255.255.255.255

˽��IP��Χ�ǣ�
10.0.0.0��10.255.255.255
172.16.0.0��172.31.255.255
192.168.0.0��192.168.255.255

��������Ϊǰ����������1��Ȼ��ȫ��0�������磺255.255.255.32����һ���Ƿ������룩
������ʱĬ����0��ͷ��IP��ַ�ǺϷ��ģ�����0.1.1.2���ǺϷ���ַ
��������:
�����ַ�����ÿ��һ��IP��ַ�����룬��~������
�������:
ͳ��A��B��C��D��E������IP��ַ��������롢˽��IP�ĸ�����֮���Կո����
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
		
		//���Զ�ȡ��ֵ�������ȡ������ֵ�����˸���˵����ʽ���� 
		ret = sscanf(str,"%d.%d.%d.%d~%d.%d.%d.%d",ip,ip+1,ip+2,ip+3,mask,mask+1,mask+2,mask+3);
		if(ret != 8)
		{
			cnt.err++;
			continue;
		}
		//��ʼ�������Ĵ���255.255.255.255Ҳ�Ǵ���� 
		net_mask = (mask[0]<<24)|(mask[1]<<16)|(mask[2]<<8)|(mask[3]<<0);
		oz_flag = 1;
		for(i=31;i>=0;i--)
		{
			if(oz_flag == 1)
			{
				if(((net_mask>>i) & 0x01) == 0)	//& �� == �����ȼ����� 
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
		//�ж�ABCDE
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
		//�ж�˽��ip
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
