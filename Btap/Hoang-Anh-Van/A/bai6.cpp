#include<stdio.h>
main()
{
	int i,dem=0,n;
	float a[100],x;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	printf("Nhap vao phan tu x can tim:");
	scanf("%f",&x);
	for (i=0;i<n;i++)
	{
		printf("Nhap vao phan tu thu %d:",i+1);
		scanf("%f",&a[i]);
    }
    for (i=0;i<n;i++)
	if (a[i]==x) dem++;
	printf("Phan tu x co mat %d lan",dem);
}

