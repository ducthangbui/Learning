#include<stdio.h>
#include<math.h>
FILE *f1=fopen("in.txt","r");
FILE *f2=fopen("out.txt","w");
int UCLN(int a,int b)
{
	if (a==0&&b==0) return 0;
	else
	{
		while (b!=0)
		{
			int tmp=b;
			b=a%b;
			a=tmp;
		}
	return fabs(a);
	}
}
int BCNN(int a, int b)
{
	if (a==0||b==0) return 0;
	else
	{
		return fabs((a*b)/UCLN(a,b));
	}
}
void in()
{
	int a,b;
	fscanf(f1,"%d%d",&a,&b);
	if(UCLN(a,b)==0) fprintf(f2,"Khong co UCLN\n");
	else fprintf(f2,"%d\n",UCLN(a,b));
	if(BCNN(a,b)==0) fprintf(f2,"Khong co BCNN");
	else fprintf(f2,"%d\n",BCNN(a,b));
}
main()
{
	in();
}
