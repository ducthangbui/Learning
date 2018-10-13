#include<stdio.h>
#include<math.h>
FILE *f1=fopen("BAI1.INP","r");
FILE *f2=fopen("BAI1.OUT","w");
int ThuanNghich(int n)
{
	int m=n;
	int tmp=0;
	int tong=0;
	while(n!=0)
	{
		tong=tong+n%10;
		tmp=tmp*10+n%10;
		n=n/10;
		//tong=tong+n%10;
	}
	if((tmp==m)&&(tong%10==0))return 1;
				return 0;
}

void SoDep()
{	
	int n;
	int t;
	fscanf(f1,"%d",&t);
	while(t--)
	{
		int dem=0;
		fscanf(f1,"%d",&n);
	for(int i=pow(10,n-1);i<(pow(10,n-1)*10);i++)
	if (ThuanNghich(i)==1) dem++;
	fprintf(f2,"%d\n",dem);
	}
	fclose(f2);
}

main()
{
	SoDep();
}
