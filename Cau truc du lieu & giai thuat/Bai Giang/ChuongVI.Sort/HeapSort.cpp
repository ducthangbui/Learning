#include <iostream>

using namespace std;

//NHap mang
void Nhap(int a[],int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap a["<<i<<"]:";
		cin>>a[i];
	}
}

//Xuat mang
void Xuat(int a[],int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
}

//Xay dung Max Heap
void MaxHeap(int a[],int i,int n)
{
	int j=2*i,tmp=a[i];
	while(j<=n)
	{
		if(j<n && a[j+1] > a[j]) j++;
		if(tmp > a[j]) break;
		else if(tmp <= a[j])
		{
			a[j/2]=a[j];
			j=2*j;
		}
	}
	a[j/2]=tmp;
}

void BuildMaxHeap(int a[],int n)
{
	for(int i=n/2;i>=1;i--)
	MaxHeap(a,i,n);
}

void HeapSort(int a[],int n)
{

	int i,tmp;
	for(int i=n;i>=2;i--)
	{
		BuildMaxHeap(a,i);//tao MaxHeap cho i-1 so con lai	
			tmp=a[i];
			a[i]=a[1];//luon doi cho cho a[1]
			a[1]=tmp;
	//	BuildMaxHeap(a,n);
	
	}
}

main()
{
	int a[100],n;
	cout<<"Nhap so phan tu cua mang:";
	cin>>n;
	Nhap(a,n);
	cout<<"Mang vua nhap la:";
	Xuat(a,n);
	cout<<endl;
	HeapSort(a,n);
	//BuildMaxHeap(a,n);
	cout<<"Mang da sap xep la:";
	Xuat(a,n);
}
