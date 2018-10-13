#include<stdio.h>
void Nhap(int a[][100],int &n,int &m)
{
	printf("Nhap vao so n:");
	scanf("%d",&n);
	printf("Nhap vao so m:");
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
void DcChinh(int a[][100],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		if(i==j) printf("%d ",a[i][j]);
		else printf(" ");
		printf("\n");
	}
}
main()
{
	int a[100][100],n,m;
	Nhap(a,n,m);
	printf("ma tra vua nhap la:\n");
	Xuat(a,n,m);
	printf("\nDuong cheo chinh cua ma tran la:\n");
	DcChinh(a,n,m);
	
}
