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
int UCLN(int a,int b)
{
	if (a==0&&b==0) return 0;
	else
	{
		while (b!=0)
		{
			int tmp=b;
			b=a%b;
			a=tmp;
		}
	return fabs(a);
	}
}
main()
{
	int x;
	scanf("%d",&x);
	int k=1,dem=0;
	while(k<=x)
	{
		k++;
		if(UCLN(k,x)==1) dem++;
	}
	//printf("%d\n",k);
	//printf("%d\n",dem);
	if(kiemtranguyento(dem)==1) printf("1");
	else printf("0");
}
