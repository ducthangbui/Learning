#include<stdio.h>
#include<math.h>
void Can(int a,int b)
{
	if(a<0)
		if(b<0) printf("Hay nhap so a>0\nHay nhap so b>0\n");
		else
		{
			printf("Hay nhap so a>0\n");
			printf("Can bac 2 cua %d la:%f\n",b,sqrt(b));
		}
	else
	{
		printf("Can bac 2 cua %d la:%f\n",a,sqrt(a));
		printf("Can bac 2 cua %d la:%f\n",b,sqrt(b));
	}
}
int Tong(int a,int b)
{
	return a+b;
}
int Hieu(int a,int b)
{
	return a-b;
}
int Tich(int a,int b)
{
	return a*b;
}
void Thuong(int a,int b)
{
	if (b==0) printf("K xac dinh");
	else
	printf("%d/%d=%f\n",a,b,(float)a/b);
}
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
void Uoc(int a,int b)
{
	if(a==0)	
		if(b==0) printf("Moi so deu la uoc cua a\nMoi so deu la uoc cua b\n");
		else
		{
			printf("Moi so deu la uoc cua a\n");
			if(b<0)
			{
				printf("Uoc so cua %d la:",b);
				for(int j=1;j<=fabs(b);j++)
				if(b%j==0) printf("%3d %3d",j,-j);
			}
			else
			{
				printf("Uoc so cua %d la:",b);
				for(int j=1;j<=b;j++)
				if(b%j==0) printf("%3d",j);
			}
		}
	else	
	{
		if(a<0)
		  if(b<0)
		  {
		  	printf("Uoc so cua %d la:",a);
		  	for(int i=1;i<=fabs(a);i++)
		  	if(a%i==0) printf("%3d %3d",i,-i);
		  	printf("\nUoc so cua %d la:",b);
		  	for(int j=1;j<=fabs(b);j++)
		  	if(b%j==0) printf("%3d %3d",j,-j);
		  }
			else
		{
			printf("Uoc so cua %d la:",a);
			for (int i=1;i<=fabs(a);i++)
			if (a%i==0)printf("%3d %3d",i,-i);
			printf("\nUoc so cua %d la:",b);
			for (int j=1;j<=b;j++)
			if (b%j==0) printf("%3d",j);
		}
		else
		{
			printf("Uoc so cua %d la:",a);
			for(int i=1;i<=a;i++)
			if(a%i==0) printf("%3d\n",i);
			printf("Uoc so cua %d la:",b);
			for(int j=1;j<=a;j++)
			if(b%j==0) printf("%3d\n",j);
		}
	}
	
}
main()
{
	int a,b;
	printf("Nhap a:");
	scanf("%d",&a);
	printf("Nhap b:");
	scanf("%d",&b);
	printf("%d+%d=%d\n",a,b,Tong(a,b));
	printf("%d-%d=%d\n",a,b,Hieu(a,b));
	printf("%d*%d=%d\n",a,b,Tich(a,b));
	Thuong(a,b);
	printf("\n");
	if (UCLN(a,b)==0) printf("Khong co UCLN\n");
	else 
	{
	printf("UCLN:%d\n",UCLN(a,b));
	};
	if (BCNN(a,b)==0) printf("Khong co BCNN\n");
	else
	{		
	printf("BCNN:%d\n",BCNN(a,b));
	}
	Can(a,b);
	Uoc(a,b);
}
