/*Sap xep chen*/
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
	printf("%2.2f ",a[i]);
}
void Sxchen(float a[],int n)
{
	int i,vtchen;
	float x;
	for (i=1;i<n;i++)
	{
		x=a[i];
		vtchen=i-1;
		while (vtchen>=0 && a[vtchen]>x)
		{
			a[vtchen+1]=a[vtchen];
			vtchen--;
		}
		a[vtchen+1]=x;
	}
}
main()
{
	float a[100];
	int n;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	Sxchen(a,n);
	printf("Day dc sap xep la:");
	Xuat(a,n);
}
