#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Tong(char a[])
{
	int tong=0;
	long long m=atol(a);
	while(m!=0)
	{
		tong+=m%10;
		m=m/10;
	}
	if(tong%10==8||tong%10==9) return 1;
	return 0;
}
int Thuannghich(char a[])
{
	int l=strlen(a)/2;
	for(int i=0;i<l;i++)
	if(a[i]!=a[l-i-1]) return 0;
	return 1;
}
int Ktra(char a[])
{
	int l=strlen(a)-1;
	if(a[l]=='6'||a[l]=='8') return 1;
	return 0;
}
main()
{
	char a[100];
	printf("Nhap chuoi:");
	gets(a);
	if(Tong(a)==1&&Thuannghich(a)==1&&Ktra(a)==1) printf("So dep\n"); 
	else printf("So xau\n");
}
