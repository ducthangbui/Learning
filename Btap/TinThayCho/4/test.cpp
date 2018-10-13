#include<stdio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
int dx(int a[],int n)
{
	int ktra=1;
	for(int i=0;i<n-1;i++)
	for(int j=n-1;j>i;j--)
	if(a[i]!=a[j]) 
	{
		ktra=0;
		break;
	}
	return ktra;
}
main()
{
	int n,a[100];
	scanf("%d",&n);
	Nhap(a,n);
	if(dx(a,n)==1) printf("Yes"); else printf("No");
}
