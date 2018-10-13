#include<stdio.h>
void Nhap(float a[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Nhap vao phan tu thu %d:",i+1);
		scanf("%f",&a[i]);
	}
}
void Xuat(float a[],int n)
{
	int i;
	for (i=0;i<n;i++)
	printf("%4f",a[i]);
}
void Doicho(float &a,float &b)
{
	float tmp=a;
	a=b;
	b=tmp;
}
void Sxluachon(float a[],int n)
{
	int i,j,vitrimin;
	for (i=0;i<n-1;i++)
	{
		vitrimin=i;
		for (j=i+1;j<n;j++)
		if (a[j]<a[vitrimin])
		vitrimin=j;
		Doicho(a[i],a[vitrimin]);
	}
}
main()
{
	int n;
	float a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	Sxluachon(a,n);
	printf("Day da sx la:");
	Xuat(a,n);
}
