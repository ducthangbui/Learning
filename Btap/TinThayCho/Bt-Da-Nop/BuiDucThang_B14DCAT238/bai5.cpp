#include<stdio.h>
#include<math.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
	printf("Nhap ptu thu %d:",i+1);
	scanf("%d",&a[i]);
	}
}
int DemNgto(int a[],int n)
{
	int k=2,ktra=0,dem=0;
	for(int i=0;i<n;i++)
	{
	for(int j=2;j<a[i];j++)
	if(a[i]%j==0) ktra++;
	if(ktra==0&&a[i]!=1&&a[i]!=0) dem++;
	}
	return dem;
}
main()
{
	int a[1000],n;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	printf("Co %d so ngto trong mang",DemNgto(a,n));
}
