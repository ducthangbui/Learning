#include<stdio.h>
int Fibo(int n)
{
	if (n==1||n==2) return 1;
	else return (Fibo(n-1)+Fibo(n-2));
}
main()
{
	int n;
	printf("Ban can tim so Fibonaxi thu bnhieu?");
	scanf("%d",&n);
	printf("So Fibonaxi thu %d la:%d",n,Fibo(n));
}
