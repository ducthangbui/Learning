#include<stdio.h>
int UCLN(int &a,int &b)
{
	while(b!=0)
	{
		int tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
main()
{
	int a=12,b=4;
	printf("%d",UCLN(a,b));
}
