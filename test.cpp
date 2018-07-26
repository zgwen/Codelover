
/*二维数组函数传递测试*/ 

#include <iostream>
#include <process.h>
using namespace std;

void testp(int data[][3])     
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cout << data[i][j]<<' ';
	
}
 

int main()
{
	int data[3][3];
	cout << "输入九个数:" << endl;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin >> data[i][j];
	cout << "输出:" << endl;
	testp(data);
	system("pause"); 
 } 
