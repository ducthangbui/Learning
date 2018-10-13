#include<stdio.h>
void NhapMaTran(int a[][100],int m,int n)
{
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		printf("a[%d][%d]:",i,j);
		scanf("%d",&a[i][j]);
	}
}
void Max(int a[][100],int m,int n)
{
	int max=a[0][0];
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	if(a[i][j]>max) max=a[i][j];
	printf("Max:%d",max);printf("\nVi tri cuc tieu: ");
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(max==a[i][j]) printf("[%d][%d]\t",i,j);
}
void Min(int a[][100],int m,int n)
{
	int min=a[0][0],k,l;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	if(a[i][j]<min) min=a[i][j];
	printf("\nMin:%d",min);
	printf("\nVi tri cuc tieu: ");
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(min==a[i][j]) printf("[%d][%d]\t",i,j);
}
main()
{
	int m,n,a[100][100];
	printf("Nhap m:");
	scanf("%d",&m);
	printf("Nhap n:");
	scanf("%d",&n);
	NhapMaTran(a,m,n);
	Max(a,m,n);
	Min(a,m,n);
}
