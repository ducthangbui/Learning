/*Liet ke xau nhi phan co do dai n bang thuat toan sin*/
#include <iostream>

using namespace std;

void Init(int x[],int n,int &OK)
{
	for(int i=1;i<=n;i++)
	x[i]=0;
	OK=1;
}

void NextBit(int x[],int n,int &OK)
{
	int i=n;
	while(i>0 && x[i]==1) x[i--]=0;
	if(i==0) OK=0;
	else x[i]=1;
}

void Xuat(int x[],int n)
{
	cout<<endl;
	for(int i=1;i<=n;i++)
	cout<<x[i]<<" ";
}

main()
{
	int x[100],n,OK;
	cout<<"Nhap n:";
	cin>>n;
	Init(x,n,OK);
	while(OK)
	{
		Xuat(x,n);
		NextBit(x,n,OK);
	}
}
