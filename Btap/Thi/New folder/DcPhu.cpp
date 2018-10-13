#include<stdio.h>
void Nhap(int a[][100],int &n)
{
	printf("Nhap vao so n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		printf("Nhap vao phan tu thu[%d][%d]:",i,j);
		scanf("%d",&a[i][j]);
	}
}
void Xuat(int a[][100],int &n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
}
void DcPhu(int a[][100],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		if((i==0&&j==0)||(i==n-1&&j==n-1)) printf(" ");
		else printf("%d ",a[i][j]);
		printf("\n");
	}
}
main()
{
	int a[100][100],n;
	Nhap(a,n);
	printf("Ma tran vua nhap la:\n");
	Xuat(a,n);
	printf("Duong cheo phu la:\n");
	DcPhu(a,n);
}
