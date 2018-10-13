#include<stdio.h>
#include<math.h>
int giaithua(int n)
{
	if (n==0||n==1) return 1;
	else return n*giaithua(n-1);
}
float ex(float x,float c,int n)
{
	float e=0;
	if ((pow(x,n)/giaithua(n))>c) 
	return 0;
	else
	for (int i=0;i<=n;i++)
		e=e+(pow(x,i)/giaithua(i));
	return e;
}
main()
{
	int n;
	float x,c;
	printf("Nhap vao so c:");
	scanf("%f",&c);
	printf("Nhap vao x:");
	scanf("%f",&x);
	printf("Nhap vao n:");
	scanf("%d",&n);
	if (ex(x,c,n)==0) printf("Khong thoa man");
	else
	if (c>0) printf("e^%.0f=%f",x,ex(x,c,n));
	else printf("Khong thoa man");
}
