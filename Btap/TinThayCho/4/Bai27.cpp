#include<stdio.h>
void Nhap(int a[][100],int &m,int &n)
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
void Xuat(int a[][100],int m,int n)
{
	printf("\nMa tran cap %dx%d la:\n",m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%2d",a[i][j]);
		printf("\n");
	}
}

void Min(int a[][100],int m,int n)
{
	int dem=0;
	int min=a[0][0];
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	if(min>a[i][j]) min=a[i][j];
	printf("\nMin:%d",min);
	for(int i=0;i<m;i++)
	for(int j=0;j<m;j++)
	if(a[i][j]==min) dem++;
	printf("\nCo %d ptu trong mang bang min",dem);	
}

main()
{
	int a[100][100],m,n;
	Nhap(a,m,n);
	Xuat(a,m,n);
	Min(a,m,n);
}
