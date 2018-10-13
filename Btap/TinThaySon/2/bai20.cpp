#include<stdio.h>
#include<math.h>
float giaithua(int n)
{
	if(n==0||n==1) return 1;
	else return n*giaithua(n-1);
}
float tong(int n,float x)
{
	float tong=0;
	for(int i=0;i<=(2*n)+1;i++)
	tong=tong+(pow(-1,i)*(pow(x,i)/giaithua(i)));
	return tong;
}
main()
{
 	float x,c;
	int n=0;
	//printf("Nhap vao x:");
	//scanf("%f",&x);
	printf("Nhap c:");
	scanf("%d",&c);
	if(c<=0) printf("Nhap lai c");
	else
	printf("Nhap x:");
	scanf("%f",&x);
	while(fabs(pow(x,(2*n)+1)/giaithua((2*n)+1))>c)
	{
		n++;
	}	
	printf("sin%.f=%f\n",x,tong(n,x));
	printf("Ham sin(%.f)=%f",sin(x));
}
