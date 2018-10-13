#include<stdio.h>
void Nhap(float a[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Nhap vao phan tu thu %d:",i+1);
		scanf("%f",&a[i]);
	}
}
void TimMin(float a[],int n)
{
	float min=a[0];
	for (int i=1;i<n;i++)
	if(a[i]<min) min=a[i];
	printf("Min=%f",min);
}
main()
{
	int n;
	float a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	TimMin(a,n);
}
