#include <iostream>

using namespace std;

void Nhap(int a[],int &n)
{
	cout<<"Nhap phan tu cua mang:";
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

void InsertSort(int a[],int n)
{
	int key;//key la phan tu can chen vao day a[0], ... , a[i-1]
	int j;
	for(int i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j >= 0 && a[j]>key)//Duet lui tu vi tri j=i-1
		{
			a[j+1]=a[j];//dic chuyen a[j] len vi tri a[j+1]
			j--;
		}
		a[j+1]=key;//vi tri thich hop cua key trong day la a[j+1]
	}
}

main()
{
	int a[100],n;
	Nhap(a,n);
	cout<<"Mang vua nhap la:";
	Xuat(a,n);
	cout<<endl;
	InsertSort(a,n);
	cout<<"Mang da sap xep la:";
	Xuat(a,n);
}
