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
	int s=0,m;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		s=s+m;
	}
	if (kiemtranguyento(s)==1) return 1;
	else return 0;
}
main()
{
	int i;
	for(i=1000000;i<=9999999;i++)
	if(ThuanNghich(i)==1&&kiemtra(i)==1&&kiemtranguyento(i)==1) printf(" %d",i);
}
