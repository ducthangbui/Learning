#include<stdio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Nhap phan tu thu %d:",i+1);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void Chen(int a[],int n,int vt,int &x)
{
	if(vt>=0&&vt<=n)
	{
		for(int i=n;i>vt;i--)
		a[i]=a[i-1];
		a[vt]=x;
		n++;
	}
}
main()
{
	int n,a[100],vt,b[100],m;
	printf("Nhap vao so phan tu cua a[]:");
	scanf("%d",&n);
	printf("Nhap so phan tu cua b[]:");
	scanf("%d",&m);
	printf("Nhap vao vi tri can chen:");
	scanf("%d",&vt);
	printf("Nhap mang a:\n");
	Nhap(a,n);
	printf("\nNhap mang b:\n");
	Nhap(b,m);
	for(int i=m-1;i>=0;i--)
	Chen(a,n+m,vt,b[i]);
	Xuat(a,n+m);
}
