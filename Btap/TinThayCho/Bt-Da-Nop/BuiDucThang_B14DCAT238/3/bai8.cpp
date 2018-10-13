#include<stdio.h>
#include<math.h>
int kiemtratang(int n)
{
	int a[100],i=0;
	while (n!=0)
	{
		a[i]=n%10;
		n=n/10;
		i++;
	}
    int j,dem=0;
    for(j=0;j<i-1;j++)
    {
                 if(a[j]>=a[j+1])
                 dem++;
    }
                    if(dem==(i-1))
                    return 1;
                    return 0;
}
int kiemtranguyento(int n)
{
	int ktra=0;
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) ktra++;
	if(ktra==0) return 1;
	else return 0;
}
int kiemtra(int n)
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
main()
{
	int i;
	for(i=10000;i<=9999999;i++)
	{
	if(kiemtratang(i)==1 && kiemtra(i)==1 && kiemtranguyento(i)==1)
	printf("%d\n",i);
	}
}
