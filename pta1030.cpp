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
	/*对排序后的数列的每个值，向后寻找最大完美子列
	 *最大复杂度2n
	 */ 
	long long temp,j=0,i=0;
	for(i=0; i < n; i++)
	{
		/*如果剩下的数列长度小于maxc，则跳出*/ 
		if(maxc >= n-1-i+1)
			break;
		/*计算当前数值的最大完美子列长度 
		 *若a[i]*p>=a[j]
		 *则必有a[i+1]*p>=a[j]
		 *故j的值不用每次都从i递增
		 */
		for(; (a[i]*p >= a[j]) && (j < n); j++);
		temp = j-1-i+1;
		if(temp > maxc)
			maxc = temp;		
	}
    printf("%d",maxc);
    return 0;
}
