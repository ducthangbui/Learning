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
void InMT(int a[][100],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%3d",a[i][j]);
		printf("\n");
	}
}
void TichMT(int a[][100],int b[][100],int m,int n,int k)
{
		for(int j=0;j<n;j++)
	{
		for(int i=0;i<m;i++)
			b[j][i]=a[i][j];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<k;j++)
		{
			int tich=0;
			for(int k=0;k<n;k++)
			tich=tich+a[i][k]*b[k][j];
			printf("%d  ",tich);
		}
		printf("\n");
	}
}
void MTHoanVi(int a[][100],int &m,int &n)
{
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<m;i++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
}
main()
{
	int a[100][100],b[100][100],m,n;
	NhapMT(a,m,n);
	printf("\nMa tran vua nhap la:\n");
	InMT(a,m,n);
	printf("\nMa tran hoan vi cua ma tran vua nhap la:\n");
	MTHoanVi(a,m,n);
	printf("\nTich cua ma tran vua nhap va ma tran hoan vi cua no la:\n");
	TichMT(a,b,m,n,m);
}
