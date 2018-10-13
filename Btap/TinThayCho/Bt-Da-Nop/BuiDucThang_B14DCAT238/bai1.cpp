#include<stdio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
	printf("Nhap ptu thu %d:",i+1);
	scanf("%d",&a[i]);
	}
}
void Tong(int a[],int n)
{
	int s=0;
	for(int i=0;i<n;i++)
	s=s+a[i];
	printf("S=%d",s);
}
main()
{
	int a[1000],n;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	Tong(a,n);
}
