#include<stdio.h>
#include<conio.h>
void Nhap(int a[],int &n)
{
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
int TimMax(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	if(max<=a[i]) max=a[i];
	return max;
}
main()
{
	int a[100],n;
	//printf("Nhap vao so phan tu:");
	//scanf("%d",&n);
	Nhap(a,n);
	TimMax(a,n);
	printf("Max=%d",TimMax(a,n));
	getch();
}
