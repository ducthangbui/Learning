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
void TimMax(float a[],int n)
{
	float max=a[0];
	for (int i=1;i<n;i++)
	if(a[i]>max) max=a[i];
	printf("Max=%f",max);
}
main()
{
	int n;
	float a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	TimMax(a,n);
}
