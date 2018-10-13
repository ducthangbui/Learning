#include<iostream>
#define MAX 100
using namespace std;
int x[MAX],n,OK,p,q;
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<"\n";
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
void Init_NB_(int *x,int &n,int &OK)
{
	cout<<"Nhap n= ";cin>>n;
	for(int i=1;i<=n;x[i]=0,i++);
	OK=1;
}
void next_bit(int *x,int n,int &OK)
{
	int i=n;
	while(i>0&&x[i]==1) x[i--]=0;
	if(i==0) 	OK=0;
	else 		x[i]=1;
}
main()
{
	Init_NB_(x,n,OK);
	cout<<"Nhap P= ";cin>>p;
	cout<<"Nhap Q= ";cin>>q;
	while(OK)
	{
		if(test()) Xuat(x,n);
		next_bit(x,n,OK);
	}
}
