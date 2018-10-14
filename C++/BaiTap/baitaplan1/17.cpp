#include<iostream>
using namespace std;
void Nhap(int &n,int a[])
{
	cout<<"Nhap vao so phan tu cua mang:";
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
}
void Max(int &n,int a[])
{
	int max1=a[0],max2=-99999;
	for(int i=0;i<n;i++)
		if(max1<a[i]) max1=a[i];
	for(int i=0;i<n;i++)
		if((max2<a[i])&&(a[i]<max1)) max2=a[i];
	if(max2==-99999) cout<<"Cung nhau";
	cout<<"Max1="<<max1<<endl<<"max 2="<<max2<<endl;
}
void Xuat(int n,int a[])
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
void Swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void Sort(int n,int a[])
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
		if(a[i]<a[j]) Swap(a[i],a[j]);
}
void Insert(int &n,int &x,int a[])
{
	cout<<"Nhap vao so can chen:";
	cin>>x;
	int i=n;
	while(x>a[i-1])
	{
		a[i]=a[i-1];
		i--;
	}
	a[i]=x;
	n++;
}
main()
{
	int n,a[100],x;
	Nhap(n,a);
	cout<<"Mang vua nhap la:"<<endl;
	Xuat(n,a);
	cout<<endl;
	Max(n,a);
	cout<<"Mang sau khi da sap xep la:"<<endl;
	Sort(n,a);
	Xuat(n,a);
	cout<<endl;
	Insert(n,x,a);
	cout<<"Mang sau khi chen la:";
	Xuat(n,a);
}
