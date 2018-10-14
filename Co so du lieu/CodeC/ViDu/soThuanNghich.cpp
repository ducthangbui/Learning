#include<stdio.h>
main()
{
	int n,m=0,tmp=n;
	printf("Nhap vao so can ktra:");
	scanf("%d",&n);
	while(n!=0)
	{
	m=m*10+n%10;
	n=n/10;	
	}
	if (m==tmp) printf("So vua nhap la so thuan nghich");
	else("So vua nhap khong phai la so thuan nghich");
}
