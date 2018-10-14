#include<iostream>
#include<cmath>
using namespace std;
int Ngto(int n)
{
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) return 0;
				return 1;
}
void Program(int n)
{
	for(int i=1;i<n;i++)
	if(Ngto(i)&&Ngto(4*i+1)) cout<<i<<"\t";
}
main()
{
	int n;
	cout<<"Nhap vao n:";
	cin>>n;
	Program(n);
}
