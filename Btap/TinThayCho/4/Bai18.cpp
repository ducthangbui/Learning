#include<stdio.h>
#include<stdlib.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void Max(int a[],int n)
{
	int max1=a[0],max2=a[0];
	int ktra1=0,ktra2=0,i;
	for(i=1;i<n;i++)
		if(a[i]>max1) max1=a[i];
	printf("Max1:%d\n",max1);
	for(i=1;i<n;i++)
	if(a[i]>max2&&a[i]!=max1) max2=a[i];
	printf("Max2:%d\n",max2);
	for(int j=0;j<n;j++)
	{
	if(a[j]==max1) printf("Vi tri max1:%d\n",j),ktra1=1;
	if(ktra1!=0) break;}
	for(int j=0;j<n;j++)
	{if(a[j]==max2) printf("Vi tri max2:%d\n",j),ktra2=1;
	if(ktra2!=0) exit(0);}
}
main()
{
	int n,a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	Max(a,n);
}
