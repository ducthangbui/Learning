#include<stdio.h>
int TimMax(int a[],int n)
{
	int max=a[0];
	for(int i=0;i<n;i++)
		if(a[i]>max) a[i]=max;
		return max;
}
main()
{
	int j,n,a[1000];
	printf("Nhap vao so phan tu:");
	scanf("%d%d",&n);
	for(j=0;j<n;j++)
	{
		printf("a[%d]:",j);
		scanf("%d",&a[j]);
	}
	printf("%d",TimMax(a,n));
}
