#include<stdio.h>
void Nhap(int a[],int &n)
{
	printf("Nhap vao so phan tu(bat buoc la so nguyen duong):");
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
void Tim(int a[],int n)
{
	int x;
	printf("Nhap vao so can tim:");
	scanf("%d",&x);
	printf("\nVi tri cua so can tim la:");
	for(int i=0;i<n;i++)
	if(a[i]==x) printf("%d ",i);
}
int kiemtratang(int a[],int n)
{
	int ktra=0;
	for(int i=0;i<n;i++)
	if(a[i]>a[i+1]) ktra=1;
	return ktra;
}
int kiemtragiam(int a[],int n)
{
	int ktra=0;
	for(int i=0;i<n;i++)
	if(a[i]<a[i+1]) ktra=1;
	return ktra;
}
void Doicho(int &x,int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}
void SxTang(int a[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=n-1;j>i;j--)
	if(a[i]>a[j]) Doicho(a[i],a[j]);
}
void SxGiam(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
		if(a[i]<a[j]) Doicho(a[i],a[j]);
}
void Max(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	if(a[i]>max) max=a[i];
	printf("Max:%d\n",max);
}
void Min(int a[],int n)
{
	int min=a[0];
	for(int i=1;i<n;i++)
	if(a[i]<min) min=a[i];
	printf("Min:%d",min);
}
void GopMang(int a[],int na,int b[],int nb)
{
	int c[100],nc=0;
	for(int i=0;i<na;i++)
	{
	c[nc]=a[i];
	nc++;
	}
	for(int i=0;i<nb;i++)
	{
		c[nc]=b[i];
		nc++;
	}
	Xuat(c,na+nb);
}
void Them(int a[],int n,int vt,int &x)
{
	if(vt>=0&&vt<=n)
	{
		for(int i=n;i>vt;i--)
		a[i]=a[i-1];
		a[vt]=x;
		n++;
	}
}
void Xoa(int a[],int vt,int &n)
{
	if(vt>=0&&vt<=n)
	{
		for(int i=vt;i>n-1;i++)
		a[i]=a[i+1];
		n--;
	}
}
void TachMang(int a[],int &n,int vt)
{
	int b[100],c[100],nb=0,nc=0;
	for(int i=0;i<vt;i++)
	{
		b[nb]=a[i];
		nb++;
	}
	for(int j=vt;j<n;j++)
	{
		c[nc]=a[j];
		nc++;
	}
	printf("Mang a[] duoc tach lam 2 mang la:\n");
	printf("Mang 1:");
	Xuat(b,nb);
	printf("\n");
	printf("Mang 2:");
	Xuat(c,nc);
}
void Sua(int a[],int n,int &vt,int &x)
{
	printf("Nhap vao vi tri(chi so mang) can sua:");
	scanf("%d",&vt);
	printf("Nhap vao phan tu moi(bat buoc la so nguyen duong):");
	scanf("%d",&x);
	a[vt]=x;
	printf("Mang sau khi sua la:");
	Xuat(a,n);
}
