#include<stdio.h>
#include<math.h>
int kiemtranguyento(int n)
{
	int ktra=0;
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) ktra++;
	if(ktra==0) return 1;
	else return 0;
}
int ThuanNghich(int n)
{
	int tmp=n,m=0;
	while(n!=0)
	{
		m=m*10+n%10;
		n=n/10;
	}
	if(m==tmp) return 1;
	else return 0;
}
int kiemtra(int n)
{
	//int a[100],i=0;
	int m,ktra=0;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		if(m==1) ktra++;
	}
	if(ktra==3) return 1;
	else return 0;
}
main()
{
	for(int i=1000000;i<=9999999;i++)
	if(ThuanNghich(i)==1&&kiemtra(i)==1&&kiemtranguyento(i)) printf(" %d",i);
}
