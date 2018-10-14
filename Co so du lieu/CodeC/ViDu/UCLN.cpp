#include<stdio.h>
main()
{
	int a,b;
	printf("Nhao vao so a:");
	scanf("%d",&a);
	printf("Nhap vao so b:");
	scanf("%d",&b);
	if (a==0&&b==0) printf("Moi so deu la UCLN");
	else
	while (b!=0)
	{
		int tmp=a;
		b=a%b;
		a=tmp;
	}
	printf("UCLN:%d",a);
}
