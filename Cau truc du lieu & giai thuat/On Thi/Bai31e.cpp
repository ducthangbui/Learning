#include <iostream>

using namespace std;

void Nhap(int a[],int n)
{
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

void HoanVi(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

//selection sort
void SelectionSort(int *Arr, int startIndex,int n)
{
	if(startIndex >=n-1)
	return ;
	int minIndex=startIndex;
	for(int i=startIndex;i<n;i++)
	{
	if (Arr[i]<Arr[minIndex ])
	minIndex=i;
	}
	HoanVi(Arr[minIndex ],Arr[startIndex ]);
	SelectionSort(Arr,startIndex+1, n);
}

main()
{
	int a[100],n;
	cout<<"Nhap so phan tu:";
	cin>>n;
	Nhap(a,n);
	cout<<"Mang vua nhap la:"<<endl;
	Xuat(a,n);
	
	cout<<endl<<"Mang sau khi sap xep la:";
	SelectionSort(a,0,n);
	Xuat(a,n);
}
