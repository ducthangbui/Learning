#include<iostream>
#define MAX 100
using namespace std;
int x[MAX],n,k;
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<endl;
}

void Init()
{
	cout<<"Nhap n= ";cin>>n;
	cout<<"Nhap k= ";cin>>k;
	x[0]=0;
}
void BackT_COM(int i=1)
{
	for(int j=x[i-1]+1;j<=n-k+i;j++)
	{
		x[i]=j;
		if(i==k) Xuat(x,k);
		else BackT_COM(i+1);
	}
}
main()
{
	Init();
	BackT_COM();
}