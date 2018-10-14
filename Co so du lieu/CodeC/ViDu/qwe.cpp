#include<stdio.h>
#include<math.h>
main()
{
	int n;
	printf("Nhap so n:");
	scanf("%d",&n);
	int c=fabs(n);
	int a[1000],i=0,max,s=0;
	
	while(c!=0)
	{
		a[i]=c%10;
		c=c/10;
		i++;
	}
	for (int j=i-1;j>=0;j--)
	{
		max=a[0];
		if (a[j]>max) a[j]=max;
		s=s+a[j];
	}
	printf("Chu so lon nhat la:%d\n",max);
	printf("Tong cac chu so la:%d",s);
}
