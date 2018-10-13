#include<stdio.h>
void Nhap(int a[],int &n)
{
	printf("Nhap vao so phan tu cua mang:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap vao phan tu thu %d:",i+1);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void Doicho(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

void Sapxep(int a[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=n-1;j>i;j--)
	{
		if((a[i]%2!=0&&a[j]%2!=0)&&(a[i]<a[j])) Doicho(a[i],a[j]);
		else if((a[i]%2==0&&a[j]%2==0)&&(a[i]>a[j])) Doicho(a[i],a[j]);
	}
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
main()
{
	int a[100],n,vt,x;
	Nhap(a,n);
	Xuat(a,n);
	printf("\n");
	Sapxep(a,n);
	Xuat(a,n);
	printf("\n");
	Sua(a,n,vt,x);
}
