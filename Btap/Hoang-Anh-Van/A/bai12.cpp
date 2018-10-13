/*Dem ky tu thuong*/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int dem=0;
	printf("Nhap vao chuoi can ktra:");
	gets(a);
	for (int i=0;i<strlen(a);i++)
	if(a[i]>=97 && a[i]<=122) dem++;//Trong bang ASCII ki tu thuong tu 97 den 122
	printf("So ky tu in hoa la:%d",dem);
}
