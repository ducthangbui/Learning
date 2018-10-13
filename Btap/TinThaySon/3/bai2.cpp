#include<stdio.h>
main()
{
	int n,m;
	printf("Nhap vao so n:");
	scanf("%d",&n);
	printf("Nhap vao so m:");
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		if (j==0||i==0||i==(m-1)||j==(n-1)) printf("*");
		else printf(" ");
		printf("\n");
	}
}
