#include "bai36g2.h" // class's header file
#include <iostream>

using namespace std;

void Bai36g2::Nhap(int &n,int a[])
{
	cout<<"Nhap vao so phan tu cua mang:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap a["<<i<<"]:";
		cin>>a[i];
	}
}

void Bai36g2::Max(int &n,int a[])
{
	int max1=a[0],max2=-99999;
	for(int i=0;i<n;i++)
		if(max1<a[i]) max1=a[i];
	for(int i=0;i<n;i++)
		if((max2<a[i])&&(a[i]<max1)) max2=a[i];
	if(max2==-99999) cout<<"Cung nhau";
	cout<<"Max1="<<max1<<endl<<"max 2="<<max2<<endl;
}

void Bai36g2::Xuat(int n,int a[])
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}

void Bai36g2::Insert(int &n,int &x,int a[])
{
	cout<<"Nhap vao so can chen:";
	cin>>x;
	int i=n;
	while(x>a[i-1])
	{
		a[i]=a[i-1];
		i--;
	}
	a[i]=x;
	n++;
}
