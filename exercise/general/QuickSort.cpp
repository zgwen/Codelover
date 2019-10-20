#include <iostream>

using namespace std;

void swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp; 
}
void QuickSort(int A[], int left, int right)
{
	if(left > right) return;	
	int mark = A[left];
	int i = left;
	int j = right;
	while(i < j){
		while(A[j] >= mark && i < j) j--;	//先从右边找一个小于mark的数 
		while(A[i] <= mark && i < j) i++;	//再从左边找一个大于mark的数 
		if(i < j) swap(A,i,j);				//交换 
	}
	A[left] = A[i];	//将mark与i=j处的值交换 
	A[i] = mark;
	QuickSort(A, left, i-1);
	QuickSort(A, i+1, right);
}

int main()
{
	int n;
	while(cin >> n){
		int A[n] = {0};
		for(int i=0; i<n; i++){
			cin >> A[i];
		}	
		QuickSort(A,0,n-1);
		for(int i=0; i<n; i++){
			cout << A[i] << ' ';
		}
		cout << endl;
	}
	
} 
