#include<stdio.h>
void Nhap(int a[][100],int &n)
{
	printf("Nhap vao cap cua ma tran vuong:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		printf("Nhap vao ptu thu [%d][%d]:",i,j);
		scanf("%d",&a[i][j]);
	}
}
void Xuat(int a[][100],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		printf("%2d",a[i][j]);
		printf("\n");
	}
}
void Dem(int a[][100],int n)
{
	int dem1=0,dem2=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(a[i][j]>0) dem1++;
		if(a[i][j]<0) dem2++;
	}
	printf("Ma tran co %d so nguyen duong.",dem1);
	printf("\nMa tran co %d so nguyen am",dem2);
}
main()
{
	int a[100][100],n;
	Nhap(a,n);
	printf("\nMa tran vuong cap %d la:\n",n);
	Xuat(a,n);
	Dem(a,n);
}
