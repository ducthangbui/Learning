#include<stdio.h>
#include<stdio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao ptu thu %d:",i);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}

void B16(int a[],int &n,int &x)
{

	int i=n++;
	while(x<a[i-1])
	{
		a[i]=a[i-1];
		i--;
	}
	a[i]=x;
	
}
main()
{
	int na,a[100],b[100],nb;
	printf("Nhap vao so phan tu:");
	scanf("%d",&na);
	Nhap(a,na);
	printf("\nNhap vao so ptu:");
	scanf("%d",&nb);
	Nhap(b,nb);
	for(int i=0;i<nb;i++)
	B16(a,na,b[i]);
	Xuat(a,na);
}
