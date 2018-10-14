#include<stdio.h>
main()
{
	int i,n,s=1;
	printf("nhap vao so n:");
	scanf("%d",&n);
	//if(n==0) printf("n! =1");
	//else
	for(i=1;i<=n;i++)
	s=s*i;
	printf("%d",s);
}
