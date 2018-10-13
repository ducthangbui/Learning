#include<stdio.h>
main()
{
	int h;
	printf("Nhap h:");
	scanf("%d",&h);
	if (h<=0) printf("Nhap lai h");
	else
	{
	printf("Tam giac can co chieu cao h la:\n");
	for (int i=0;i<h;i++)
	{
		for (int j=0;j<=(2*h-1);j++)
		if (j>=h-i&&j<=h+i) printf("*");
		else printf(" ");
		printf("\n");
	}
	}
}
