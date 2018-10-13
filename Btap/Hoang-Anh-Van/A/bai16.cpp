/*dem so ki tu la chu so trong chuoi*/
#include<stdio.h>
#include<string.h>
main()
{
	char a[100];
	int dem=0;
	printf("Nhap vao chuoi can ktra:");
	gets(a);
	for (int i=0;i<strlen(a);i++)
	if(a[i]>='0' && a[i]<='9') dem++;
	printf("So ki tu la chu so la:%d",dem);
}
