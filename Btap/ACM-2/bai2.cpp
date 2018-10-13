#include<stdio.h>
#include<math.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
main()
{
	int n,k,a[1000];
	printf("Nhap n:");
	scanf("%d",&n);
	printf("Nhap k:");
	scanf("%d",&k);
	Nhap(a,n);
	int i=0,dem=0,j=0;
	while(i<n)
	{
		while(j<n)
		{
		if(fabs(a[i]-a[j])<=k) dem++;
		j++;
		}
		i++;
	}
	printf("%d",dem);
}


