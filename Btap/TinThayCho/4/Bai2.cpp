#include<stdio.h>
#include<conio.h>
void DoiCho(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void SxTang(int a[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	if(a[i]>=a[j]) DoiCho(a[i],a[i+1]);
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
main()
{
	int a[100],n;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	SxTang(a,n);
	Xuat(a,n);
	getch();
}
