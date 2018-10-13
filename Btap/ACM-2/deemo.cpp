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
main()
{
	int n;
	scanf("%d",&n);
	if(kiemtranguyento(n)==1) printf("Yes");
	else printf("No");
}
