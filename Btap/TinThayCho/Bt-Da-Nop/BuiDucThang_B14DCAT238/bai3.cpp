#include<stdio.h>
void Fibo(int a[100],int n)
{
	a[0]=0,a[1]=1;
	for(int i=2;i<n;i++)
	a[i]=a[i-1]+a[i-2];
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%3d",a[i]);
}
main()
{
	int n,a[100];
	printf("Hay nhap so n:");
	scanf("%d",&n);
	printf("Day Fibonaxi voi %d so dau la:",n);
	Fibo(a,n);
	Xuat(a,n);
}
