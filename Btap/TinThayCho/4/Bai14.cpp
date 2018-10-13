#include<stdio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void DoiCho(int &a,int &b)
{
	int tmp=a;
		a=b;
		b=tmp;
}
void BubbleSort(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
		if(a[i]>a[j]) DoiCho(a[i],a[j]);
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
main()
{
	int n,a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	BubbleSort(a,n);
	Xuat(a,n);
}
