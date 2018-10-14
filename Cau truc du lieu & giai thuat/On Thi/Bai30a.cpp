#include <iostream>
#define MAX 100
using namespace std;
void Init_NB_(int *x,int &n,int &OK)
{
	cout<<"Nhap n= ";cin>>n;
	for(int i=1;i<=n;x[i]=0,i++);
	OK=1;
}
void next_bit(int *x,int n,int &OK)
{
	int i=n;
	while(i>0&&x[i]==1) x[i--]=0;//in sau khi tru
	if(i==0) 	OK=0;
	else 		x[i]=1;
}
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<endl;
}

main()
{
	int n,OK,x[MAX];
	Init_NB_(x,n,OK);
	while(OK)
	{
		Xuat(x,n);
		next_bit(x,n,OK);
	}
}
