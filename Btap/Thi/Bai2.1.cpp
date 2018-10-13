#include<stdio.h>
#include<math.h>
FILE *f1=fopen("BAI2.1.INP","r+");
FILE *f2=fopen("BAI2.1.OUT","w");
int ngto(int n)
{
	if(n<=1) return 0;
	int ktra=0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) ktra++;
	if(ktra==0) return 1;
	return 0;
}
int tach(int n)
{
	int ktra=0,i=0;
	while(n!=0)
	{
		int m=n%10;
		if(ngto(m)==1) ktra++;
		n=n/10;
		i++;
	}	
	if(ktra==i) return 1;
	return 0;
}
int tong(int n)
{
	int tong=0;
	while(n!=0)
	{
		 tong+=n%10;
		 n/=10;
	}
	if(ngto(tong)==1) return 1;
	return 0;
}
void Bai1()
{
	int n,t,m;
	fscanf(f1,"%d",&t);
	while(t--)
	{
		    int dem=0;
			fscanf(f1,"%d%d",&n,&m);
			for(int i=n;i<=m;i++)
			if(tong(i)==1&&tach(i)==1&&ngto(i)==1) dem++;
			fprintf(f2,"%d\n",dem);
	}	
	fclose(f2);
}
main()
{
	Bai1();
}
