#include<stdio.h>
void Nhap(int a[][100],int &n,int &m)
{
	printf("Nhap so nguyen duong m:");
	scanf("%d",&m);
	printf("Nhap so nguyen duong n:");
	scanf("%d",&n);
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
		{
			printf("Nhap vao ptu [%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
}
void Xuat(int a[][100],int n,int m)
{
	for(int i=0;i<m;i++)
	{	
		for(int j=0;j<n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
}
void MTHoanVi(int a[][100],int &n,int &m)
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
	int a[100][100],b[100][100],n,m;
	Nhap(a,n,m);
	printf("Ma tran cac so nguyen cap mxn vua nhap la:\n");
	Xuat(a,n,m);
	printf("\n\n");
	printf("Ma tran chuyen vi la:\n");
	MTHoanVi(a,n,m);
}
