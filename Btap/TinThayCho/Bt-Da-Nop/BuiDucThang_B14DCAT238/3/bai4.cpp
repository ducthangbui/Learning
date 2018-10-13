#include<stdio.h>
#include<math.h>
int tong(int n)
{
	int s=0,m;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		s=s+m;
	}
	return s;
}
void TichNgto(int n)
{
	int i=2;
	while(i<=sqrt(n))
	{
		while(n%i==0)
		{
			if(n==i) printf("%d",i);
			else printf("%d*",i);
			n=n/i;
		}
		i++;
	}
	if(n>1) printf("%d",n);
}
main()
{
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	printf("Tong cac chu so la:%d\n",tong(n));
	TichNgto(n);
}
