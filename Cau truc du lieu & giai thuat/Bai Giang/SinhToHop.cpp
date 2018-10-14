/*Sinh nhi phan to hop chap k cua n phan tu*/
#include <iostream>

using namespace std;

int x[100];
int n,k;
bool ok=true;

void init()
{
	cout<<"Nhap n:";
	cin>>n;
	cout<<"Nhap k:";
	cin>>k;
	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap x["<<i<<"]:";
		cin>>x[i];
	}
}

void Sinh()
{
	int i=k;
	while(i>0 && x[i]==n-k+i)
	{
		i--;
	}
	if(i>0)
	{
		x[i]++;
		for(int j=i+1;j<=k;j++)
		x[j]=x[i]+j-i;
	}
	else ok=false;
}

void Xuat()
{
	for(int i=1;i<=k;i++)
	cout<<x[i]<<" ";
}

int main()
{
	init();
	while(ok)
	{
		Xuat();
		cout<<endl;
		Sinh();
	}
	return 0;
}
