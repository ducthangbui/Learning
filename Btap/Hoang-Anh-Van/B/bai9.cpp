#include<stdio.h>
main()
{
	float a[100];
	int n,i;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%f",&a[i]);
	}
	float max=a[0];
	for(i=1;i<n;i++)
	if(max<a[i]) max=a[i]; 
	printf("Max:%f\n Tai vi tri:%d",max,i);
}

