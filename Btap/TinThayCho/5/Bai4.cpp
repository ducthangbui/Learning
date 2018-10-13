#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
long long Tong(char a[],char b[])
{
	long long c=atol(a);
	long long d=atol(b);
	return c+d;
}
long long Hieu(char a[],char b[])
{
	long long c=atol(a);
	long long d=atol(b);
	return c-d;
}
long long Tich(char a[],char b[])
{
	long long c=atol(a);
	long long d=atol(b);
	return c*d;
}
float Thuong(char a[],char b[])
{
	float c=atof(a);
	float d=atof(b);
	if(d==0) return 0;
	else return c/d;
}
main()
{
	char a[200],b[200];
	gets(a);
	gets(b);
	printf("Tong:%lld\n",Tong(a,b));
	printf("Hieu:%lld\n",Hieu(a,b));
	printf("Tich:%lld\n",Tich(a,b));
	if(Thuong(a,b)==0) printf("K xac dinh\n");
	else printf("Thuong:%.3f",Thuong(a,b));
}
