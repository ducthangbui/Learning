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


void SelectionSort(int a[],int n)
{
	int tmp;
	int minIndex;//phan tu nho nhat trong day con
	for(int i=0;i<n-1;i++)
	{
		minIndex=i;//goi minIndex la vi tri phan tu nho nhat trong day con
		for(int j=i+1;j<n;j++)
		{
			if(a[i] > a[minIndex]) minIndex=j;//ghi nhan phan tu nho nhat trong day con
		}
		//dat lai phan tu nho nhat vao vi tri dau tien cua day con chua duoc sap xep
		tmp=a[i];
		a[i]=a[minIndex];
		a[minIndex]=tmp;
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
