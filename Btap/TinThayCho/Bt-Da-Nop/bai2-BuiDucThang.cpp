#include<stdio.h>
#include<math.h>
main()
{
	int n;
	printf("Nhap so n:");
	scanf("%d",&n);
	int c=fabs(n);
	int max=0,s=0,m;
	while(c!=0)
	{
		m=c%10;
		c=c/10;
		if(m>max) max=m;
		s=s+m;
	}
	printf("Chu so lon nhat la:%d\n",max);
	printf("Tong cac chu so la:%d",s);
}
