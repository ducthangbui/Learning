#include<stdio.h>
#include<math.h>
float tong(float n)
{
	float s=0;
	float i,dau;
	for(i=0;i<=n;i++)
	{
		dau=pow(-1,i);
	s=s+(dau*(1/(2*i+1)));
	}
	return s;
}
main()
{
	float c,n=0;
	printf("Nhap vao so c:");
	scanf("%f",&c);
	if (c<=0) printf("Hay nhap c>0");
	else
	while(1>(c*(2*n+1)))
	{
		n++;
	}
	printf("PI=%f",4*tong(n));
}
