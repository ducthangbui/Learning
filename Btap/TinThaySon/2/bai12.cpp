#include<stdio.h>
int Fibo(int n)
{
	if (n==1||n==2) return 1;
	else return (Fibo(n-1)+Fibo(n-2));
}
main()
{
	int n;
	scanf("%d",&n);
	printf("%d",Fibo(n));
}
