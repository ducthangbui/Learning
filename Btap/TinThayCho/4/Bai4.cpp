#include<stdio.h>
#include<conio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
int DemX(int a[],int n,int x)
{
	int dem=0;
	for(int i=0;i<n;i++)
	if(a[i]==x) dem++;
	return dem;
}
main()
{
	int x,n,a[100];
	printf("Nhap x:");
	scanf("%d",&x);
	printf("Nhap so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	printf("So lan xuat hien cua %d la:%d",x,DemX(a,n,x));
	getch();
}
