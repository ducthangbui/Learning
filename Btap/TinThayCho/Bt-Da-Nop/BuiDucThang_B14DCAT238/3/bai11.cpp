#include<stdio.h>
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
int Tong(int n)
{
	int s=0,m;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		s=s+m;
	}
	if(s%10==0) return 1;
	else return 0;
}
int kiemtra(int n)
{
	int ktra=0,m;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		if(m!=0||m!=6||m!=8) ktra++;
	}
	if(ktra==0) return 1;
	else return 0;
}
main()
{
	for(int i=1000000;i<=999999999;i++)
	if(ThuanNghich(i)==1&&Tong(i)==1&&kiemtra(i)==1) printf(" %d",i);
}
