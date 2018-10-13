#include<stdio.h>
void Nhap(int a[],int n)
{
	
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void Max2(int a[],int n)
{
	int max1=a[0];
	int max2=a[0],vtri;
	for(int i=1;i<n;i++)
	{
	if(a[i]>max1) max1=a[i];
	//if(a[i]>max2&&a[i]!=max1) max2=a[i];
	}
	for(int i=1;i<n;i++)
	if(a[i]>max2&&a[i]!=max1) 
		{
			max2=a[i],vtri=i;
		}
	//printf("%d\n",max1);
	printf("Max2:%d",max2);
	printf("\nVi tri max2:%d",vtri);
}
main()
{
	int a[100],n;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	Max2(a,n);
}
