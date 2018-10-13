#include<stdio.h>
#include<math.h>
main()
{
	int n;
	printf("Nhap so n:");
	scanf("%d",&n);
	int c=fabs(n);
	int max=0,s=0,dem=0,a[100],ktra=0,dem1=0;
	while(c!=0)
	{
		a[s]=c%10;
		c=c/10;
		s++;
	}
	for(int j=0;j<s;j++)
	{
	if(a[s]>a[s+1]) ktra++;
	if(a[s]%2==0) dem++;
	else dem1++;
	}
	if(ktra==(s-1)) printf("Tang\n");
	printf("%d %d",dem,dem1);
}
