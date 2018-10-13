#include<stdio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void Doicho(int &x,int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}
void SxTang(int a[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=n-1;j>i;j--)
	if(a[i]<a[j]) Doicho(a[i],a[j]);
}
main()
{
	int n,a[100];
	scanf("%d",&n);
	Nhap(a,n);
	SxTang(a,n);
	Xuat(a,n);
}
