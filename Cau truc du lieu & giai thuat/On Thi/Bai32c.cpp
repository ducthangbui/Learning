#include <iostream>

using namespace std;

int n,x[100];
bool daxet[100];

void Xuat()
{
	for(int i=1;i<=n;i++)
	cout<<x[i]<<" ";
	cout<<endl;
}

void Try(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(daxet[j] == false)
		{
			x[i]=j;
			daxet[j]=true;
			if(i==n) Xuat();
			else Try(i+1);
			daxet[j]=false;
		}
	}
}

int main()
{
	cout<<"Nhap n:";
	cin>>n;
	Try(1);
	return 0;
}
