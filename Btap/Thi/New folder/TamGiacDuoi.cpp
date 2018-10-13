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
void TamGiacDuoi(int a[][100],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		dem++;
		for(int j=0;j<n;j++)
		if(dem<=j) printf(" ");
		else printf("%2d",a[i][j]);
		printf("\n");
	}
}
main()
{
	int a[100][100],n;
	Nhap(a,n);
	printf("Ma tran vua nhap la:\n");
	Xuat(a,n);
	printf("\nMa tran tam giac tren la:\n");
	TamGiacDuoi(a,n);
}
