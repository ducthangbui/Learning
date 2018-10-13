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
	printf("Ma tran cap %dx%d la:\n",m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%4d",a[i][j]);
		printf("\n");
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void Max(int a[][100],int m,int n)
{
	int b[100],nb=0;
	//int max=a[0][0];
	for(int i=0;i<m;i++)
	{
		int max=a[i][0];
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>max) max=a[i][j];
			b[nb]=max;
		}
		nb++;
	}
	printf("Cac ptu Max trong tung hang cua ma tran la:");
	Xuat(b,nb);
}
main()
{
	int a[100][100],m,n;
	NhapMT(a,m,n);
	XuatMT(a,m,n);
	Max(a,m,n);
}
