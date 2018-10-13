#include<iostream>
#define MAX 100
#include<fstream>
using namespace std;
fstream fi;
int x[MAX],a[MAX],c[MAX],n,b,kq[MAX],maxi=0,OK;
// c la mang chua gia tri su dung
// a la mang chua trong luong cac do
// b la khoi luong toi da dc mang theo
// kq la mang luu ket qua toi uu
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<"\n";
}
void Init()
{
	fi.open("cai tui.txt");
	fi>>n>>b;
	for(int k=1;k<=n;k++) fi>>c[k];
	for(int i=1;i<=n;i++) {fi>>a[i];kq[i];}
	OK=1;
	fi.close();
}
void Update()
{
	int tonga=0,tongc=0;
	for(int i=1;i<=n;i++)
	{
		tongc+=c[i]*x[i];
		tonga+=a[i]*x[i];
	}
	if(tonga>b) return ;
	if(tongc>maxi)
	{
		maxi=tongc;
		for(int i=1;i<=n;i++)
			kq[i]=x[i];
	}
}
void BackT_BIT(int i=1)
{
	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if(i==n) Update();
		else BackT_BIT(i+1);
	}
}
main()
{
	Init();
	BackT_BIT();
	Xuat(kq,n);
}
