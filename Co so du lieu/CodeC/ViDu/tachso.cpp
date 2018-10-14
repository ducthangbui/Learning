#include<stdio.h>
#include<math.h>
int Max(int a[],int n)
{
	int max=a[0];
	for (int i=1;i<n;i++)
	if (a[i]<max) max=a[i];
	return max;
}
main()
{
	int n;
	printf("Nhap so n:");
	scanf("%d",&n);
	int c=fabs(n);
	int a[1000],i=0,max,s=0,j;
	while(c!=0)
	{
		a[i]=c%10;
		c=c/10;
		i++;
	}
	//max=a[0];
	for(j=i-1;j>=0;j--)
		//if (a[j]>max) a[j]=max;
		//printf("%d",Max(a,i));
	printf("%3d",a[j]);
}
