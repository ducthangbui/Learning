
#include<stdio.h>
#include<math.h>
int giaithua(int n)
{
	int s=1;
	for(int i=1;i<=n;i++)
	s=s*i;
	return s;
}
int Tohop(int k,int n)
{
	int c=giaithua(n)/(giaithua(n-k)*giaithua(k));
	return c;
}
main()
{
	int n,i=1;
	printf("Nhap n:");
	scanf("%d",&n);
	while(i<=n)
	{
		for(int j=0;j<=i;j++)
		printf("%3d ",Tohop(j,i));
		printf("\n");
		i++;
	}
}
