#include<stdio.h>
#include<math.h>
int ktra(int n)
{
	int ktra=0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) ktra++;
	if(ktra==0) return 1;
	else return 0;
}
void innguyento(int n)
{
	int dem=0,i=2;
	printf("\n%d so nguyen to dau la:",n);
	while(dem<n)
	{
		if(ktra(i)==1) dem++,
		printf("%d ",i);
		i++;
	}
	//printf("\n%d ",i);
}
void Fibo(int a[],int n)
{
	a[0]=0,a[1]=1;
	for(int i=2;i<n;i++)
	a[i]=a[i-1]+a[i-2];
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
main()
{
	int n,a[100];
	printf("Hay nhap so n:");
	scanf("%d",&n);
	printf("Day Fibonaxi voi %d so dau la:",n);
	Fibo(a,n);
	Xuat(a,n);
	innguyento(n);
}
