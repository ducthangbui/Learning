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
main()
{
	float c,x;
	int n=0;
	printf("Nhap vao so c:");
	scanf("%f",&c);
	if(c<=0) printf("Hay nhap c>0");
	else
	printf("Nhap vao x:");
	scanf("%f",&x);
	while(fabs((pow(x,n)/giaithua(n)))>0)
	{
		n++;
	}
	//printf("%f",n);
	printf("e^%.f=%f",x,tong(n,x));
}
