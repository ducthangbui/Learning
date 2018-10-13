/*Chuyen chu hoa sang chu thuong*/
#include<stdio.h>
#include<string.h>
main()
{
	char a[100];
	printf("Nhap vao xau can chuyen:");
	gets(a);
	printf("Xau sau khi da chuyen la:%s",strlwr(a));
}
