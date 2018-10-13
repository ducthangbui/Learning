#include<stdio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
	printf("Nhap ptu thu %d:",i+1);
	scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%3d",a[i]);
}
void Sxtang(int a[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	if(a[i]>=a[j])
	{
		int tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	}
}
main()
{
	int a[1000],n;
	printf("Nhap so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	Sxtang(a,n);
	Xuat(a,n);
}
