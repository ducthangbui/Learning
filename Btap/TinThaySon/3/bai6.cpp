#include<stdio.h>
#include<math.h>
int UCLN(int a,int b)
{
	{
	//if (a==0&&b==0) return 0;
	//else
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
}
main()
{
	int a,b,c;
	printf("Nhap a:");
	scanf("%d",&a);
	printf("Nhap b:");
	scanf("%d",&b);
	if(a>b) printf("Hay nhap a<b");
	else 
	{
	if(a<0)
		if(b<0) printf("Hay nhap so a>0\nHay nhap so b>0\n");
		else printf("Hay nhap so a>0\n");
	else
	{
		for(int i=a;i<=b;i++)
		{
		for(int j=a;j<=b;j++)
		if(UCLN(i,j)==0) printf(" K co UCLN");
		else 
		if(UCLN(i,j)==1) printf("%3d %3d\n",i,j);
		}
	}
	}
}
