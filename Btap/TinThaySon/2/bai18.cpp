#include<stdio.h>
#include<math.h>
float tong(int n)
{
	float s=0;
	for(int i=0;i<=n;i++)
	s=s+pow(-1,i)*1/(2*i+1);
	return s;	
}
main()
{
	float c,s=0;
	printf("Nhap vao so c:");
	scanf("%f",&c);
	int n=0;
	while (((2*n+1)*c)<1)
	{
		n++;
	}
	printf("PI=%f",4*tong(n));
}
