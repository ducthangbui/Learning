#include<stdio.h>
main()
{
	float a[100];
	int i,n;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%f",&a[i]);
	}
	float x;
	printf("Nhap vao phan tu x:");
	scanf("%f",&x);
	for(i=0;i<n;i++)
	
	if (a[i-1]<=x&&a[i]>=x) 
	{
	n++;
	float tmp=a[i];
	x=a[i];
	tmp=a[i+1];
	//n++;
	}
	
    for (i=0;i<n;i++)
    printf("%.2f ",a[i]);
}
