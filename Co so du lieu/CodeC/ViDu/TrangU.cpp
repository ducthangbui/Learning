#include<stdio.h>
int TrangU(int n)
{
	int a[100],i=0;
	while(n!=0)
	{
		a[i]=n%10;
		n=n/10;
		i++;
	}
	if(a[0]==a[i-1]) return 1;
	return 0;
}
main()
{
	int n;
	printf("Nhap so can ktra:");
	scanf("%d",&n);
	if(TrangU(n)==1) printf("Dung roi!!!\n");
	else printf("Cha phai!!!");
}
