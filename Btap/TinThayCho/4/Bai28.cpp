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
		printf("Nhap ptu thu [%d][%d]:",i,j);
		scanf("%d",&a[i][j]);
	}
}
void XuatMT(int a[][100],int m,int n)
{
	printf("Ma tran cap %dx%d la:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%2d",a[i][j]);
		printf("\n");
	}
}
void Doicho(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void Sxtang(int a[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=n-1;j>i;j--)
	if(a[i]>a[j]) Doicho(a[i],a[j]);
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void Sx(int a[][100],int &m,int &n)
{
	int b[100],nb=0;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		b[nb]=a[i][j];
		nb++;
	}
	Sxtang(b,nb);
	printf("Cac ptu cua ma tran sau khi dc sx tang dan la:");
	Xuat(b,nb);
}
main()
{
	int a[100][100],m,n;
	NhapMT(a,m,n);
	XuatMT(a,m,n);
	Sx(a,m,n);
}
