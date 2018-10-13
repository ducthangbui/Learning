/*InsertSort de quy*/
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

void InsertSort(int a[],int i,int n)
{
	if(i >= n) return;
	int key;//key la phan tu can chen

	int j;
	key=a[i];
	j=i-1;
	while(j >= 0 && a[j] > key)
	{
		a[j+1]=a[j];
		j--;
	}
	a[j+1]=key;
	InsertSort(a,i+1,n);	
}

main()
{
	int a[100],n;
	Nhap(a,n);
	cout<<endl<<"Day vua nhap la:";
	Xuat(a,n);
	
	cout<<endl<<"Day sau khi sap xep la:";
	InsertSort(a,1,n);
	Xuat(a,n);
}
