#include<stdio.h>
#include<math.h>
float giaithua(int n)
{
	if(n==0||n==1) return 1;
	else return n*giaithua(n-1);
}
float tong(int n,float x)
{
	float s=0;
	for(int i=0;i<=n;i++)
	s=s+(pow(x,i)/giaithua(i));
	return s;
}
float emu(float x,float c)
{
	int n=0;
	while(fabs((pow(x,n)/giaithua(n)))>c)
	{
		n++;
	}
	//printf("%f",n);
	return tong(n,x);
	//printf("e^%.f=%f",x,tong(n,x));
}
float amu(float a,float x,float c)
{
	return emu(x*log(a),c);
}
main()
{
	float x,c,a;
	printf("Nhap x:");
	scanf("%f",&x);
	printf("Nhap c:");
	scanf("%f",&c);
	printf("nhap a:");
	scanf("%f",&a);
	printf("e^%.f=%f\n",x,emu(x,c));
	//printf("Nhap a:");
	//scanf("%f",&a);
	printf("%.f^%.f=%f",a,x,amu(a,x,c));
	
}

