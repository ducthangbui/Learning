#include <iostream>
#include <fstream>
using namespace std;
ifstream iFile("DAYSO.INP");
ofstream oFile("SXCHON.OUT");
void Nhap(int a[],int &n)
{
	
	iFile>>n;
	for(int i=0;i<n;i++)
	{
		iFile>>a[i];
	}
}

void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	oFile<<a[i]<<" ";
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
	oFile<<"Mang vua nhap:";
	Xuat(a,n);
	InsertSort(a,n);
	oFile<<endl<<"Sap xep noi bot:";
	Xuat(a,n);
}
