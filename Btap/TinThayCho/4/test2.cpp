#include<stdio.h>
#include<string.h>
main()
{
	char *mau;
	printf("Nhap mau:");
	gets(mau);
	switch (mau)
	{
		case R:printf("RED");break;
		case G:printf("Green");break;
		default: printf("BLACK");
	}
}
