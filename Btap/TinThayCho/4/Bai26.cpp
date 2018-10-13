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
void InMT(int a[][100],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%3d",a[i][j]);
		printf("\n");
	}
}
void DoiCho(int *a,int &b)
{
	int tmp = (*a);
	*a=b;
	b=tmp;
}
void B26(int a[][100],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		int *min;
		min=&a[i][0];
		for(int j=0;j<n;j++)
			if(*min>a[i][j])
				DoiCho(min,a[i][j]);
	}
}
main()
{
	int a[100][100],m,n;
	NhapMT(a,m,n);
	printf("\nMa tran vuan nhap la:\n");
	InMT(a,m,n);
	printf("\n");
	B26(a,m,n);
	InMT(a,m,n);
}
