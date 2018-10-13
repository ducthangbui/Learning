#include<stdio.h>
main()
{
	char mau[100];
	printf("Nhap vao mau:");
	gets(mau);
	switch(mau)
	{
		case R:case r: printf("RED");break;
		default: printf("BLACK"); break;
	}
}
