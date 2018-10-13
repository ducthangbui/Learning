#include<stdio.h>
void Nhap(int a[],int &n)
{
	printf("Nhap so phan tu cua mang:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap ptu thu %d:",i+1);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void Xoa(int a[],int &n,int vt)
{
	if(vt>=0&&vt<n)
	{
		for(int i=vt;i<n-1;i++)
		a[i]=a[i+1];
		n--;
	}	
}
void XoaGt(int a[],int &n,int &x)
{
	printf("Nhap vao gia tri can xoa:");
	scanf("%d",&x);
	for(int i=0;i<n;i++)
	if(x==a[i]) Xoa(a,n,i);
}
main()
{
	int a[100],n,x;
	Nhap(a,n);
	printf("Mang da nhap la:\n");
	Xuat(a,n);
	printf("\n");
	XoaGt(a,n,x);
	printf("Mang sau khi xoa la:\n");
	Xuat(a,n);
}
