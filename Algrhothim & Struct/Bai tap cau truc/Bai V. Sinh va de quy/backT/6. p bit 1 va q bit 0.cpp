#include<iostream>
#define MAX 100
using namespace std;
int x[MAX],n,k,m,p,q;
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<"\n";
}
void Init()
{
	cout<<"Nhap n= ";cin>>n;
	cout<<"Nhap P= ";cin>>p;
	cout<<"Nhap Q= ";cin>>q;
}
bool test()
{
	int d1=0,s1=0,d0=0,s0=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]==1) {d1++;d0=0;}
		else {d1=0;d0++;}
		if(d0>=q) s0++;
		if(d1>=p) s1++;
	}
	if(s0==1&&s1==1) return true;
	return 0;
}
void BackT_BIT(int i=1)
{
	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if(i==n) 
		{
			if(test()) Xuat(x,n);
		}
		else BackT_BIT(i+1);
	}
}
main()
{
	Init();
	BackT_BIT();
}