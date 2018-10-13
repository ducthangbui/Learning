#include<stdio.h>
void Nhap(int a[][100],int &n,int &m)
{
	printf("Nhap vao hang cua ma tran:");
	scanf("%d",&n);
	printf("Nhap vao cot cua ma tran:");
	scanf("%d",&m);
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		printf("Nhap vao phan tu thu [%d][%d]:",i,j);
		scanf("%d",&a[i][j]);
	}
}
void Xuat(int a[][100],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
}
void XoaHang(int a[][100],int &n,int m,int &vt)
{
	printf("Nhap vao hang can xoa:");
	scanf("%d",&vt);
	for(int i=vt;i<n;i++)
	{
		for(int j=0;j<m;j++)
		a[i][j]=a[i+1][j];
		n--;
	}
}
void XoaCot(int a[][100],int n,int &m,int &vt)
{
	printf("Nhap vao cot can xoa:");
	scanf("%d",&vt);
	for(int i=0;i<n;i++)
		for(int j=vt;j<m;j++)
		a[i][j]=a[i][j+1];
		m--;
}
void ThemHang(int a[][100],int &n,int m,int &vt,int b[])
{
	printf("Nhap vao vi tri can them:");
	scanf("%d",&vt);
	for(int i=n;i>vt;i--)
	{
	for(int j=m-1;j>=0;j--)
		{
			a[i][j]=a[i-1][j];
			a[vt][j]=b[j];
		}
			n++;
	}
}
void ThemCot(int a[][100],int n,int &m,int &vt,int b[])
{
	printf("Nhap vao vi tri can them:");
	scanf("%d",&vt);
	for(int i=n-1;i>=0;i--)
	{
	for(int j=m;j>vt;j--)
	{
		a[i][j]=a[i][j-1];
		
	}
	a[i][vt]=b[i];}
	m++;
}
main()
{
	int a[100][100],b[100],n,m,vt;
	Nhap(a,n,m);
	printf("\nMa tran vau nhap la:\n");
	Xuat(a,n,m);
	printf("\n");
	//XoaCot(a,n,m,vt);
		printf("Nhap vao cac phan tu can them:\n");
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao ptu thu %d:",i+1);
		scanf("%d",&b[i]);
	}
	ThemCot(a,n,m,vt,b);
	printf("\nMa tran sau khi da xoa cot la:\n");
	Xuat(a,n,m);
}
