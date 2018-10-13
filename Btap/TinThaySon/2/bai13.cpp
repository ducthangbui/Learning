#include<stdio.h>
main()
{
	int n,m=0;
	printf("Nhap vao so can ktra:");
	scanf("%d",&n);
	int tmp=n;
	while (n!=0)
	{
	m=m+n%10;
	n=n/10;	
	}
	printf("Tong cac chu so la:%d\n",m);
}
