/*
1030 ��������(25)��25 �֣�

����һ�����������У���������p������������е����ֵ��M����Сֵ��m�����M <= m * p���������������������С�
���ڸ�������p��һЩ���������������ѡ�񾡿��ܶ��������һ���������С�
�����ʽ��
�����һ�и�������������N��p������N��<= 10^5^����������������ĸ�����p��<= 10^9^���Ǹ����Ĳ������ڶ��и���N����������ÿ����������10^9^��
�����ʽ��
��һ�������������ѡ����ٸ����������������һ���������С�
����������
10 8
2 3 20 4 5 1 6 7 8 9
���������
8
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h> 
using namespace std;

bool cmp(int a,int b)
{
    return a<b;
}

int main()
{
    long long n,p;
    long long *a = NULL;
    scanf("%d %d",&n,&p);
    a = (long long *)malloc(n*sizeof(long long));
    for(long long i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    long long maxc=1;
//    while(a[i]*p<=a[n-1]&&i<n)
//    {
//        int cnt=maxc;
//        while(a[cnt]<=a[i]*p&&cnt<n)
//        {
//            cnt++;
//            cnt = cnt - i;
//            if(cnt>maxc)
//                maxc = cnt;            
//        }
//
//        i++;
//    }
	/*�����������е�ÿ��ֵ�����Ѱ�������������
	 *����Ӷ�2n
	 */ 
	long long temp,j=0,i=0;
	for(i=0; i < n; i++)
	{
		/*���ʣ�µ����г���С��maxc��������*/ 
		if(maxc >= n-1-i+1)
			break;
		/*���㵱ǰ��ֵ������������г��� 
		 *��a[i]*p>=a[j]
		 *�����a[i+1]*p>=a[j]
		 *��j��ֵ����ÿ�ζ���i����
		 */
		for(; (a[i]*p >= a[j]) && (j < n); j++);
		temp = j-1-i+1;
		if(temp > maxc)
			maxc = temp;		
	}
    printf("%d",maxc);
    return 0;
}