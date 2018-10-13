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
void Tim(int a[][100],int m,int n,int &x)
{
	printf("Nhap vao so nguyen duong can tim kiem:");
	scanf("%d",&x);
	int dem=0;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	if(a[i][j]==x) dem++;
	//printf("So lan xuat hien cua ptu %d la:%d",x,dem);
	printf("%d xuat hien %d lan lan luot tai cac vi tri la:",x,dem);
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	if(a[i][j]==x) printf("(%d,%d) ",x,i,j);
}
main()
{
	int a[100][100],x,m,n;
	NhapMT(a,m,n);
	printf("Ma tran vua nhap la:\n");
	XuatMT(a,m,n);
	printf("\n");
	Tim(a,m,n,x);
}
