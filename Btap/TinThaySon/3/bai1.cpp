#include<stdio.h>
main()
{
	int n,m;
	printf("Nhap vao so n:");
	scanf("%d",&n);
	printf("Nhap vao so m:");
	scanf("%d",&m);
	printf("Hinh chu nhat canh n*m la:\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		printf("*");
		printf("\n");
	}
}
