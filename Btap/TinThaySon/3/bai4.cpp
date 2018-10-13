#include<stdio.h>
main()
{
	int i,j,h;
	printf("Nhap h:");
	scanf("%d",&h);
	for (i=0;i<h;i++)
	{
		for (j=0;j<(2*h-1);j++)
		if (j=h||j==h-i||j==h+i) printf("*"),printf("\n");
		else printf(" ");
	}
}

