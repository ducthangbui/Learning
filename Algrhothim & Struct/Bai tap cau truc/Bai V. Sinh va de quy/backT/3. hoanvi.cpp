#include<iostream>
#define MAX 100
using namespace std;
int x[MAX],n,chuaxet[MAX];
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<"\n";
}
void Init()
{
	cout<<"Nhap n=";cin>>n;
	for(int i=1;i<=n;i++) chuaxet[i]=1;
}

void BackT_PER(int i=1)
{
	for(int j=1;j<=n;j++)
	{
		if(chuaxet[j]) 
		{
			x[i]=j;
			chuaxet[j]=0;
			if(i==n) Xuat(x,n);
			else BackT_PER(i+1);
			chuaxet[j]=1;
		}
	
	}
}
main()
{
	Init();
	BackT_PER();
}