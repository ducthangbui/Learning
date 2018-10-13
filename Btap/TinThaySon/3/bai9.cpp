#include<stdio.h>
main()
{
	int n,dem=0,m=0,a[100],ktra=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(n%i==0) a[m]=i,m++,printf("%3d",i),dem++;
	//printf("%d ",songto(c));
	}
	
	printf("\nSo uoc la:%d\n",dem);
	printf("Cac uoc so la so ngto la:");
	for(int j=1;j<=m;j++)
	{
		int k=2;
		while(k<a[j])
		{
		if(a[j]%k==0) ktra++;
		k++;
		}
		if(ktra==0) printf("%d ",a[j]);
	}
}
