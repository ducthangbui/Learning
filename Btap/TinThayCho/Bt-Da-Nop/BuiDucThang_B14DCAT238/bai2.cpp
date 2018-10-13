#include<stdio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
	printf("Nhap ptu thu %d:",i+1);
	scanf("%d",&a[i]);
	}
}
void Max(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	if(a[i]>=max) max=a[i];
	printf("Max=%d",max);
}
main()
{
	int a[1000],n;
	printf("Nhap so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	Max(a,n);
}
