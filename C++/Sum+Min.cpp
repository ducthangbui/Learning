#include<iostream>
using namespace std;
void Nhap(int &n, float a[])
{
	cout<<"Nhap n:";
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
}
void Xuat(int n,float a[])
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
float Tong(int n,float a[])
{
	float tong=0;
	for(int i=0;i<n;i++)
	tong+=a[i];
	return tong;
}
float Min(int n,float a[])
{
	float min=a[0];
	for(int i=1;i<n;i++)
	if(min>a[i]) min=a[i];
	return min;
}
main()
{
	int n;
	float a[100];
	Nhap(n,a);
	cout<<"Day vua nhap la:";
	Xuat(n,a);
	cout<<"\nTong:"<<Tong(n,a);
	cout<<"\nMin:"<<Min(n,a);
}
