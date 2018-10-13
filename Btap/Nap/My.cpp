#include<stdio.h>
main()
{
	int a,b;
	printf("Nhap a:");
	scanf("%d",&a);
	printf("Nhap b:");
	scanf("%d",&b);
	while(b>0)
	{
		int r=a%b;
		a=b;
		b=r;
	}
	printf("Dap an la:%d",a);
}
