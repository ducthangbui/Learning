#include<iostream>
#define MAX 100
using namespace std;
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<"\n";
}
void next_per(int *x,int n,int &OK)
{
	int i=n-1;
	while(i>0&&x[i]>x[i+1]) i--;
	if(i==0) OK=0;
	else
	{
		int j=n;
		while(x[j]<x[i]) j--;
		int r=x[i];x[i]=x[j];x[j]=r;
		int a=i+1,b=n;
		while(a<b)
		{
			r=x[a];x[a]=x[b];x[b]=r;
			a++;b--;
		}
	}
}
void Init_NP_(int *x,int &n,int &OK)
{
	cout<<"Nhap n= ";cin>>n;
	for(int i=1;i<=n;x[i]=i,i++);
	OK=1;
}
main()
{
	int x[MAX],n,OK;
	Init_NP_(x,n,OK);
	while(OK)
	{
		Xuat(x,n);
		next_per(x,n,OK);
	}
}
