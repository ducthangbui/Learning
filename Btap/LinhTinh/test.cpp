#include<stdio.h>
#include<math.h>
	FILE *f1=fopen("BAI6.TXT","r+");
	FILE *f2=fopen("KQBAI6.TXT","w");
int thuannghich(int n)
{
	int dao=0;
	int m=n;
	while(n>0)
	{
		dao=dao*10+n%10;
		n=n/10;
	}
	if(dao==m) return 1;
		return 0;
}
int tongcs(int n)
{
	int sum=0;
	while(n>0)
	{
		sum+=n%10;
		n/=10;
	}
	return sum;
}
main()
{
	int i,n,t;
	int k;
	fscanf(f1,"%d",&t);
	while(t--)
	{
		int dem=0;

		fscanf(f1,"%d",&n);
		k=pow(10,n-1);
		for(i=k;i<k*10;i++)
			if(thuannghich(i)==1 && tongcs(i)%10==0)
				dem++;
		fprintf(f2,"%d\n",dem);
	}
	fclose(f2);
}
