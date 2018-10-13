#include<stdio.h>
void Nhap(int a[],int &n)
{
	printf("Nhap so phan tu:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap ptu thu %d:",i+1);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void Dem(int a[],int n,int &x)
{
	int dem=0,i;
	printf("Nhap ptu can dem:");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	if(x==a[i]) dem++;
	printf("Phan tu %d xuat hien %d lan",x,dem);
}
main()
{
	int a[100],n,x;
	Nhap(a,n);
	printf("Mang vua nhap la:\n");
	Xuat(a,n);
	printf("\n");
	Dem(a,n,x);
}
