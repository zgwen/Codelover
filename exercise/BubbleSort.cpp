#include <iostream>

using namespace std;

void swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp; 
}

void BubbleSort(int A[], int n)
{
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(A[j] > A[j+1])
				swap(A, j, j+1);
		}
	}
}

int main()
{
	int n;
	while(cin >> n){
		int A[n] = {0};
		for(int i=0; i<n; i++){
			cin >> A[i];
		}	
		BubbleSort(A,n);
		for(int i=0; i<n; i++){
			cout << A[i] << ' ';
		}
		cout << endl;
	}
	
} 
