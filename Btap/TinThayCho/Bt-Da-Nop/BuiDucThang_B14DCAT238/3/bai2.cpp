#include<stdio.h>
int ThuanNghich(int n)
{
	int tmp=n,m = 0;
	while(n!=0)
	{
		m= m * 10 + n%10;
		n=n/10;
	}
	if(m==tmp) return 1;
	else return 0;
}
main()
{
	
	for(int i=100000;i<=999999;i++)
	{
	if (ThuanNghich(i)==1) printf(" %d ",i);
	}
}
