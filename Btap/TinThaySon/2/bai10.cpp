#include<stdio.h>
#include<math.h>
main()
{
	int n,i=2;
	printf("Nhap vao so n:");
	scanf("%d",&n);
	while (i<=sqrt(n))
	{
		while (n%i==0)
		{
			if (n==i) printf("%d",i);
			else printf("%d*",i);
			n=n/i;
		}
		i++;
	}
	if (n>1) printf("%d",n);
}
