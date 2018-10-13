#include<stdio.h>
main()
{
	int a[100],i=0,n;
	printf("Nhap vao so can chuyen:");
	scanf("%d",&n);
	while (n!=0)
	{
		a[i]=n%2;
		n=n/2;
		i++;
	}
	for (int j=i-1;j>=0;j--)
	printf("%3d",a[j]);
}
