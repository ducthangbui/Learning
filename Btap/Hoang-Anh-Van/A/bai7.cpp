#include<stdio.h>
main()
{
	int i,n;
	float a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("Nhap vao phan tu thu %d:",i+1);
		scanf("%f",&a[i]);
	}
	float s=0;
	for (i=0;i<n;i++)
	if (a[i]>0) s=s+a[i];
	printf("S=%f",s); 
}
