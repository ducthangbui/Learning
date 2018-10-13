#include<stdio.h>
void Nhap(int a[],int &n)
{
	printf("Nhap vao so ptu cua mang:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao ptu thu %d:",i+1);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void Thay(int a[],int &n,int &x,int &vt)
{
	printf("Nhap vao ptu can thay:");
	scanf("%d",&x);
	printf("Nhap vao vi tri can thay:");
	scanf("%d",&vt);
	for(int i=0;i<n;i++)
		if(vt==i) a[i]=x; 
}
main()
{
	int a[100],n,x,vt;
	Nhap(a,n);
	printf("Mang vua nhap la:\n");
	Xuat(a,n);
	printf("\n");
	Thay(a,n,x,vt);
	printf("Mang sau khi thay la:\n");
	Xuat(a,n);
}
