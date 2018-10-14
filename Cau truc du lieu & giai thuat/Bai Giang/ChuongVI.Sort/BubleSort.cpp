#include <iostream>

using namespace std;

void Nhap(int a[],int &n)
{
	cout<<"Nhap so phan tu cua mang:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap a["<<i<<"]:";
		cin>>a[i];
	}
}

void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}

void BubleSort(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
		if(a[i] > a[j])
		{
			int tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
}

main()
{
	int a[100],n;
	Nhap(a,n);
	cout<<"Mang vua nhap:";
	Xuat(a,n);
	BubleSort(a,n);
	cout<<endl<<"Sap xep noi bot:";
	Xuat(a,n);
}
