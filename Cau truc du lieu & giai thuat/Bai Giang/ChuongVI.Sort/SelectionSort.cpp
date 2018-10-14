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


//selection sort
void swap(int *p,int *q){
	int temp=*p;
	*p=*q;
	*q=temp;
}
void SelectionSort(int a[],int n){
	int min;
	for(int i=0;i<n-1;i++){
		min=i;//gan cho phan tu dau tien cua mang gia tri nho nhat
		for(int j=i+1;j<n;j++)
			if(a[j]<a[min])
				min=j;
		swap(&a[min],&a[i]);
	}
}

main()
{
	int a[100],n;
	Nhap(a,n);
	cout<<"Mang vua nhap la:";
	Xuat(a,n);
	cout<<endl;
	SelectionSort(a,n);
	cout<<"Mang da sap xep la:";
	Xuat(a,n);
}
