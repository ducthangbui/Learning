
#include<stdio.h>
#include<string.h>
main()
{
	char a[100];
	printf("Nhap chuoi:");
	gets(a);
	int dem=1;
	for (int i=0;i<strlen(a);i++)
	{
		if (a[i]==32) dem=dem+1;
	}
	printf("Chuoi da nhap co %d tu",dem);
}
