#include<stdio.h>
#include<math.h>
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

int kiemtrasonguyento(int &n)
{
	int dem=0;
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) dem++;
	if(dem==0) return 1;
				return 0;
}

void Ngto(int a[][100],int m,int n)
{
	int b[100][100],bi=0,bj=0;
	for(int i=0;i<m;i++)
		{
		for(int j=0;j<n;j++)
			if(kiemtrasonguyento(a[i][j])==1) printf("%d ",a[i][j]);
			else printf(" ");
			printf("\n");
	}
	//printf("\nCac so ngto tuong uong tren tung hang cua ma tran la:\n");
	//printf("\nSo 0 thay the cho cac so k phai la so nguyen to trong ma tran\n");
	//XuatMT(b,m,n);
}
main()
{
	int a[100][100],m,n;
	NhapMT(a,m,n);
	printf("\nMa tran vua nhap la:\n");
	XuatMT(a,m,n);
	Ngto(a,m,n);
}
