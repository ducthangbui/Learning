#include<stdio.h>
main()
{
	int h,i=0;
	printf("Nhap h:");
	scanf("%d",&h);
	while (i<h)
	{
		for (int j=0;j<=i;j++)
		printf("*");
		printf("\n");
		i++;
	}
	
}
