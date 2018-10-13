#include<iostream>
#include<conio.h>
#include<vector>
#include<math.h>
using namespace std;
int x[]={0,32,17,49,89,6,25,53,61},n=8;
// sap xep tang dan
void select_sort()
{
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
		if(x[i]>x[j]) 
		{
			int r=x[i];x[i]=x[j];x[j]=r;
		}
}
void bubble_sort()
{
	int k;
	do
	{
		k=0;
		for(int i=1;i<n;i++) 
			if(x[i]>x[i+1])
			{
				int r=x[i];x[i]=x[i+1];x[i+1]=r;
				k++;
			}
	}while(k);
	
}
void insert_sort()
{
	for(int i=2;i<=n;i++)
	{
		int k=x[i];
		int j=i-1;
		while(x[j]>k&&j>=1) {x[j+1]=x[j];j--;}
		if(j!=i-1) x[j+1]=k;
		
	}
}
void Quick_sort(int left,int right)
{
	int i=left,j=right,k=x[left];	
	do
	{
		while(x[i]<k&&i<right)i++;
		while(x[j]>k&&j>left)j--;
		if(i<=j)
		{
			int r=x[i];x[i]=x[j];x[j]=r;
			i++;j--;
		}
	}while(i<j);
	if(j>left) Quick_sort(left,j);
	if(i<right) Quick_sort(i,right);
}
void xuat()
{
	for(int i=1;i<=n;i++)
	cout<<x[i]<<' ';
	cout<<endl;
}
void Heap_sort()
{
	x[0]=1000000;
	int spt=n;
	while(spt!=1)
	{
		for(int i=2;i<=spt;i++)//bo sung tung phan tu vao heap 1
		{
			int k=i;
			while(x[k]>x[k/2])
			{
				int r=x[k];x[k]=x[k/2];x[k/2]=r;
				k/=2;
			}
		}
		int r=x[1];x[1]=x[spt];x[spt]=r;
		spt--;
	}
}
void Merge(int l,int td,int r)
{
	int c[100],a=l,b=td+1;
	for(int i=l;i<=r;i++)
		if(a<=td) 
			if(b<=r)
				if(x[a]<x[b])  c[i]=x[a++];
				else c[i]=x[b++];
			else c[i]=x[a++];
		else if(b<=r) c[i]=x[b++];
	for(int i=l;i<=r;i++)
		x[i]=c[i];
}
void Merge_sort(int left,int right)
{
	if(left>=right) return;
	int td=(left+right)/2;
	Merge_sort(left,td);
	Merge_sort(td+1,right);
	Merge(left,td,right);
}
void Radix_sort()
{
	vector <int> Loai[11];
	int maxi=x[1],k=0;
	for(int i=2;i<=n;i++) if(x[i]>maxi) maxi=x[i];
	while(maxi)
	{
		maxi/=10;
		k++;
		int a=int(pow(10,k)),b=int(pow(10,k-1));
		for(int i=1;i<=n;i++) 	
			Loai[(x[i]%a)/b].push_back(x[i]);
		int m=1;
		for(int i=0;i<=9;i++)
			while(!Loai[i].empty())
			{
				x[m]=Loai[i].back();
				Loai[i].pop_back();
				m++;
			}
	}
}
main()
{
//	Quick_sort(1,n);
//	insert_sort();
//	select_sort();
//	bubble_sort();
//	Heap_sort();
//	Merge_sort(1,n);
//	Merge_sort(1,n);
//	Merge(1,4,8);
//	Radix_sort();
//	xuat();
}
