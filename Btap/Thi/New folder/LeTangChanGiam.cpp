#include<stdio.h>
void Nhap(int a[],int &n)
{
	printf("Nhap so phan tu cua mang:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap ptu thu %d:",i+1);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void DoiCho(int &x,int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}
void SxTang(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	for(int j=n-1;j>i;j--)
	if(a[i]>a[j]) DoiCho(a[i],a[j]);
}
void SxGiam(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	for(int j=n-1;j>i;j--)
	if(a[i]<a[j]) DoiCho(a[i],a[j]);
}
void Sx(int a[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=n-1;j>i;j--)
	if(a[i]%2!=0&&a[j]%2!=0&&a[i]>a[j]) DoiCho(a[i],a[j]);
	else DoiCho(a[i],a[j]);
}
main()
{
	int a[100],n;
	Nhap(a,n);
	printf("\nMang vua nhap la:\n");
	Xuat(a,n);
	printf("\nMang sau khi da sap xep la:\n");
	Sx(a,n);
	Xuat(a,n);
}
