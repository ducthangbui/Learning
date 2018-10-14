/*Heap Tree*/
#include <iostream>

using namespace std;

int heapSize=0;

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

//xay dung Min Heap
void MinHeap(int a[],int i,int n)
{
	int j=2*i,tmp=a[i];
	while(j<=n)
	{
		if(j<n && a[j+1] < a[j]) j++;
		if(tmp < a[j]) break;
		else if(tmp >= a[j])
		{
			a[j/2]=a[j];
			j=2*j;
		}
	}
	a[j/2]=tmp;
}

void BuildMinHeap(int a[],int n)
{
	for(int i=n/2;i>=1;i--)
	MinHeap(a,i,n);
}

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

//Lay vi tri cua node cha
int Parent(int i)
{
	return (i-1)/2;
}

//Them moi khoa K vao MaxHeap
void InsertKeyMaxHeap(int k,int a[],int &n)
{
	n++;
	a[n]=k;
	int t=n;
	while(a[t/2] < k)
	{
		a[t]=a[t/2];
		t=t/2;
		a[t]=k;
	}
}

void InsertKeyMinHeap(int k,int a[],int &n)
{
	n++;
	a[n]=k;
	int t=n;
	while(a[t/2] > k)
	{
		a[t]=a[t/2];
		t=t/2;
		a[t]=k;
	}
}

//Xoa node tai vi tri pos
void DeleteMinHeap(int pos,int a[],int &n)
{
	for(int i=pos;i<=n;i++)
	a[i]=a[i+1];
	n--;
	BuildMinHeap(a,n);
}

main()
{
	int a[100],n;
	cout<<"Nhap so phan tu cua mang:";
	cin>>n;
	Nhap (a,n);
		
/*	BuildMaxHeap(a,n);
	InsertKeyMaxHeap(10,a,n);
	cout<<"Max Heap:";
	Xuat(a,n);
*/	
	BuildMinHeap(a,n);
	cout<<endl<<"Min Heap:";
	Xuat(a,n);
	DeleteMinHeap(2,a,n);
	cout<<endl<<"Min Heap:";
	Xuat(a,n);
}
