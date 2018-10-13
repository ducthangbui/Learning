#include<iostream>
#define MAX 100
#include<fstream>
using namespace std;
ifstream fi;
int x[MAX],a[MAX],c[MAX],n,b,kq[MAX],OK,maxi=0;
// c la mang chua gia tri su dung
// a la mang chua trong luong cac do
// b la khoi luong toi da dc mang theo
// kq la mang luu ket qua toi uu
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<"\n";
}
void next_bit(int *x,int n,int &OK)
{
	int i=n;
	while(i>0&&x[i]==1) x[i--]=0;
	if(i==0) 	OK=0;
	else 		x[i]=1;
}
void Init()
{
	fi.open("cai tui.txt");
	fi>>n>>b;
	for(int k=1;k<=n;k++) fi>>c[k];
	for(int i=1;i<=n;i++) {fi>>a[i];kq[i]=x[i]=0;}
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
main()
{
	Init();
	while(OK)
	{
		Update();
		next_bit(x,n,OK);
	}
	//Xuat(x,n);
	Xuat(kq,n);
}
