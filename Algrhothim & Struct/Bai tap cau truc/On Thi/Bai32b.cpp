#include <iostream>

using namespace std;

int x[100],n;
int k;//lay ra k phan tu 

void Nhap()
{

	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap x["<<i<<"]:";
		cin>>x[i];
	}
}

void Xuat()
{
	for(int i=1;i<=k;i++)
		cout<<x[i]<<" ";
		cout<<endl;
}

void Try(int i)
{
	for(int j=x[i-1]+1;j<=n-k+i;j++)
	{
		//cout<<"x[i-1]="<<x[i-1]<<" ";
		x[i]=j;
		if( i==k ) Xuat();
		else Try(i+1);
	}	
}

int main()
{
	cout<<"Nhap so phan tu:";
	cin>>n;

	Nhap();
	cout<<"Nhap k:";
	cin>>k;
	
	Try(1);
	return 0;
}
