#include<stdio.h>
int TimMax(int a[],int n)
{
	int max=a[0];
	for(int i=n;i<=0;i++)
		if(a[i]>max) a[i]=max;
		return max;
}
main()
{
	int n,a[1000];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	printf("Max=%d",TimMax(a,n));
}
