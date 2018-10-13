#include<iostream>
#define MAX 100
using namespace std;
int x[MAX],n,chuaxet[MAX],tong=0;
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<"\n";
}
void Init()
{
	cout<<"Nhap n=";cin>>n;
}

void BackT_DIV(int i=1)
{
	for(int j=1;j<=n;j++)
	{
		x[i]=j;
		tong=tong+j;
		if(tong==n) Xuat(x,i);
		else if(tong<n) BackT_DIV(i+1);
		tong=tong-j;
	}
}
main()
{
	Init();
	BackT_DIV();
}