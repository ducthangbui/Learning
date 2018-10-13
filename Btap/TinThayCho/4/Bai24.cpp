#include<stdio.h>
void NhapMT(int a[][100],int m,int n)
{
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
main()
{
	int a[100][100],b[100][100],m,n,k;
	printf("Nhap vao so nguyen duong m:");
	scanf("%d",&m);
	printf("Nhap vao so nguyen duong n:");
	scanf("%d",&n);
	printf("Nhap vao so nguyen duong k:");
	scanf("%d",&k);
	NhapMT(a,m,n);
	printf("\nMa tran vua nhap la:\n");
	InMT(a,m,n);
	printf("\n");
	NhapMT(b,n,k);
	printf("\nMa tran vua nhap la:\n");
	InMT(b,n,k);
	printf("\n");
	printf("\nTich cua 2 ma tran la:\n");
	TichMT(a,b,m,n,k);
}
