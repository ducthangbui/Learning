#include<stdio.h>

void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void Kc(int a[],int n)
{
	int dem,b[100];
	for(int i=0;i<n;i++)
	{
		dem=1;
		for(int j=i;j<n-1;j++)
		if(a[j]<=a[j+1]) dem++;
		else break;
		b[i]=dem;
	}
	int max=b[0];
	for(int i=1;i<n;i++)
	if(b[i]>max) max=b[i];
	printf("Max:%d\n",max);
	for(int i=0;i<n;i++)
	if(b[i]==max) printf("Vi tri:%d\n",i);
	
}
main()
{
	int n,a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	Kc(a,n);
}
