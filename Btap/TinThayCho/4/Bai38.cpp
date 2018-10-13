#include<stdio.h>
void NhapMT(int *a,int m,int n)
{

	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		printf("Nhap vao ptu thu [%d][%d]:",i,j);
		scanf("%d",a+i*m+j);
	}
}
void XuatMT(int *a,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%3d",*(a+i*m+j));
		printf("\n");
	}
}
void Tim(int *a,int m,int n)
{
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	if(((*(a+i*m+j))==(*(a+i*m+(j+1))))||((*(a+i*m+j))==(*(a+(i+1)*m+j)))) printf("Vi tri dau tien la:(%d,%d)",i,j);
}
main()
{
	int a[100];
	int m,n;
	printf("Nhap vao so nguyen duong m:");
	scanf("%d",&m);
	printf("Nhap vao so nguyen duong n:");
	scanf("%d",&n);
	NhapMT(a,m,n);
	printf("Ma tran vua nhap la:\n");
	XuatMT(a,m,n);
	printf("\n");
	Tim(a,m,n);
}
