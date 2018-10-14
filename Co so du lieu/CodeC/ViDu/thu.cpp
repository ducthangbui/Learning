#include<stdio.h>
#include<math.h>
float tong(float n)
{
	float s=1,dau=-1;
	for(int i=1;i<=n;i++)
	{
		s=s+(dau*(1/(2*n+1)));
		dau=dau*(-1);
	}
	return s;
	
}
main()
{
	float n,c;
	printf("Nhap vao so c:");
	scanf("%f",&c);
	while(1>((2*n+1)*c))
	{
		n++;
	}
	printf("PI=%f",tong(n));
}
