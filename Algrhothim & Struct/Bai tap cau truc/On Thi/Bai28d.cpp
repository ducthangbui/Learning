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

void Swap(int &x,int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}

int Partition(int a[],int l,int h)//l la can duoi cua day con; h la can tren cua day con
{
	int x=a[h];//Chon x la chot cua day
	int i=l-1;
	for(int j=l;j<=h-1;j++)
	{
		if(a[j] <= x)
		{
			i++;
			Swap(a[i],a[j]);			
		}
	}
	Swap(a[i+1],a[h]);
	return i+1;
}

void QuickSort(int a[],int l,int h)
{
	if(l<h)
	{
		int p=Partition(a,l,h);//thuc hien Partition chot h
		QuickSort(a,l,p-1);//thuc hien Quick Sort nua ben trai
		QuickSort(a,p+1,h);//thuc hien Quick Sort nua ben phai
	}
}

main()
{
	int a[100],n;
	Nhap(a,n);
	cout<<"Day vua nhap la:";
	Xuat(a,n);
	QuickSort(a,0,n);
	cout<<endl<<"Day sau khi da sap xep la:";
	Xuat(a,n);
}
