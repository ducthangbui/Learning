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
	printf("%2f ",a[i]);
}
void Doicho(float &a,float &b)
{
	float tmp;
	tmp=a;
	a=b;
	b=tmp;
}
void Sxnoibot(float a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=n-1;j>i;j--)
	if (a[j]<a[j-1]) Doicho(a[j],a[j-1]);
}
int Sxnoibot1(float a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=n-1;j>i;j--)
	if (a[j]<a[j-1]) Doicho(a[j],a[j-1]);
	return 1;
}
main()
{
	float a[100];
	int n;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	Sxnoibot(a,n);
	Xuat(a,n);
	if(Sxnoibot1(a,n)==1) printf("Day da sx tang");
}
