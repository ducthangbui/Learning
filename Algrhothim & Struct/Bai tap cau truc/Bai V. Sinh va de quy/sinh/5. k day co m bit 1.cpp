#include<iostream>
#define MAX 100
using namespace std;
int x[MAX],n,OK,k,m;
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<endl;
}

bool test()
{
	int dem1=0,soday=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]==1) dem1++;
		else dem1=0;
		if(dem1>=m) soday++;
	}
	if(soday==k) return true;
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
	cout<<"Nhap K= ";cin>>k;
	cout<<"Nhap M= ";cin>>m;
	while(OK)
	{
		if(test()) Xuat(x,n);
		next_bit(x,n,OK);
	}
	
}
