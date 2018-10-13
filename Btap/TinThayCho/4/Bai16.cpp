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
void B16(int a[],int &n,int x)
{
	int i=n;
	while(x<a[i-1])
	{
		a[i]=a[i-1];
		i--;
	}
	a[i]=x;
	n++;
}
main()
{
	int x,n,a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	printf("Nhap vao x:");
	scanf("%d",&x);
	B16(a,n,x);
	Xuat(a,n);
}
