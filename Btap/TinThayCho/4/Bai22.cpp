#include<stdio.h>
void Nhap(int a[],int &n)
{
	printf("Nhap so phan tu:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Phan tu thu %d:",i+1);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void SxChen(int a[],int n)
{
	int i,vtchen,x;
	for(int i=1;i<n;i++)
	{
		x=a[i];
		vtchen=i-1;
		while(vtchen>=0&&a[vtchen]>x)
		{
			a[vtchen+1]=a[vtchen];
			vtchen--;
		}
		a[vtchen+1]=x;
	}
}
main()
{
	int a[100],n;
	Nhap(a,n);
	SxChen(a,n);
	Xuat(a,n);
}
