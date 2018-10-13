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
void Dem(int a[],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
		//for(int j=i+1;j<n;j++)
	if(a[i]==a[i+1]) dem++;
	printf("So cap bang nhau la:%d",dem);	
}
main()
{
	int n,a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	Dem(a,n);
	getch();
}
