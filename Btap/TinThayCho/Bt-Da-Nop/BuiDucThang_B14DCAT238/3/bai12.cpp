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
int Chuso(int n)
{
	int m,i=0,ktra=0;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		i++;
		if(kiemtranguyento(m)==1) ktra++;
	}
	if(ktra==i) return 1;
	else return 0;
}
int Dao(int n)
{
	int tmp=n,m=0;
	while(n!=0)
	{
		m=m*10+n%10;
		n=n/10;
	}
	if(kiemtranguyento(m)==1) return 1;
	return 0;
}
main()
{
	for(int i=1000000;i<=9999999;i++)
	if(kiemtranguyento(i)==1&&Chuso(i)==1&&Dao(i)==1) printf(" %d",i);
}
