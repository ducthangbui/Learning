#include<stdio.h>
void NhapMT(int a[][100],int &n)
{
	printf("Nhap vao so nguyen duong n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		printf("Nhap vao phan tu thu [%d][%d]:",i,j);
		scanf("%d",&a[i][j]);
	}
}
void DuongCheo(int a[][100],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		if(i==j) printf(" "); else 
		if(i!=j) printf("%3d",a[i][j]);
		printf("\n");
	}
}
main()
{
	int a[100][100],n;
	NhapMT(a,n);
	printf("\n");
	DuongCheo(a,n);
}
