#include<stdio.h>
void Nhap(int a[],int &n)
{
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
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
void TachMang(int a[],int &n,int vt)
{
	int b[100],c[100],nb=0,nc=0;
	for(int i=0;i<vt;i++)
	{
		b[nb]=a[i];
		nb++;
	}
	for(int j=vt;j<n;j++)
	{
		c[nc]=a[j];
		nc++;
	}
	printf("Mang a[] duoc tach lam 2 mang la:\n");
	Xuat(b,nb);
	printf("\n");
	Xuat(c,nc);
}
main()
{
	int a[100],b[100],c[100],vt,n;
	Nhap(a,n);
	printf("Nhap vao vt:");
	scanf("%d",&vt);
	TachMang(a,n,vt);
	
}
