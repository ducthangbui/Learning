#include<iostream>
#define MAX 100
using namespace std;
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<"\n";
}
void next_div(int *x,int &k,int &OK)
{
	int i=k;
	while(i>0&&x[i]==1) i--;
	if(i>0) 
	{
		x[i]--;
		int d=k-i+1;
		int r=d/x[i];
		int s=d%x[i];
		k=i;
		if(r>0)
		{
			for(int j=i+1;j<=i+r;j++)
				x[j]=x[i];
			k+=r;
		}
		if(s>0)
		{
			k++;x[k]=s;
		}
	}
	else OK=0;
}
void Init_ND_(int *x,int &n,int &k,int &OK)
{
	cout<<"Nhap n= ";cin>>n;
	k=OK=1;
	x[1]=n;
}
main()
{
	int n,x[MAX],k,OK;
	Init_ND_(x,n,k,OK);
	while(OK)
	{
		Xuat(x,k);
		next_div(x,k,OK);
	}
}
