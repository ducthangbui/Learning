#include<stdio.h>
void NhapMT(int a[][100],int &m,int &n)
{
	printf("Nhap vao so nguyen duong m:");
	scanf("%d",&m);
	printf("Nhap vao so nguyen duong n:");
	scanf("%d",&n);
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		printf("Nhap vao ptu thu [%d][%d]:",i,j);
		scanf("%d",&a[i][j]);
	}
}
void XuatMT(int a[][100],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%3d",a[i][j]);
		printf("\n");
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
int Max(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	if(a[i]>max) max=a[i];
		return max;
}
void Tong(int a[][100],int m,int n)
{
	int b[100]={0},nb=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		b[nb]=b[nb]+a[i][j];
		nb++;
	}
	printf("\nTong cac hang cua Ma tran la:");
	Xuat(b,nb);
	for(int i=0;i<nb;i++)
	if(b[i]==Max(b,nb)) printf("\nChi so Hang Max cua ma tran la:%d",i);
}
main()
{
	int a[100][100],m,n;
	NhapMT(a,m,n);
	printf("\nMa tran vua nhap la:\n");
	XuatMT(a,m,n);
	printf("\n");
	Tong(a,m,n);
}
