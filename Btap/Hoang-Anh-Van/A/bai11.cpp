/*Dem ky tu hoa*/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int dem=0;
	printf("Nhap vao chuoi can ktra:");
	gets(a);
	for (int i=0;i<strlen(a);i++)
	if(a[i]>='A' && a[i]<='Z') dem++;//chu in hoa trong bang ASCII la tu 65 den 90
	printf("So ky tu in hoa la:%d",dem);
}
