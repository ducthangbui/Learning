#include<stdio.h>
#include<math.h>
main()
{
	int m,dv;
	printf("Nhap:");
	scanf("%d",&m);
	int lc=0;
	int n=fabs(m);
	while (n!=0)
	{
		dv=n%10;
		n=n/10;
		if(dv>lc) lc=dv;
	}
	printf("%d",lc);
}
