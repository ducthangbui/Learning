#include<stdio.h>
void Nhap(int a[],int &n)
{
	printf("Nhap vao bac cua da thuc:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("He so thu %d la:",i+1);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void Tong(int a[],int n,int b[],int m)
{
	int c[100];
	int nc=0;
	//for(int i=0;i<n;i++)
	//for(int j=0;j<m;j++)
	int i=0,j=0;
	while(i<n||j<m)
	{
		c[nc]=a[i]+b[j];
		nc++;
		i++; j++;
		if(i>=n) a[i]=0;
		else if(j>=m) b[j]=0;
	}
	printf("Cac he so cua da thuc tong la:");
	Xuat(c,nc);
}
main()
{
	int a[100],b[100],n,m;
	printf("Da thuc P(x)\n");
	Nhap(a,n);
	printf("Cac he so vua nhap la:");
	Xuat(a,n);
	printf("\n");
	printf("Da thuc Q(x)\n");
	Nhap(b,m);
	printf("Cac he so vua nhap la:");
	Xuat(b,m);
	printf("\n");
	Tong(a,n,b,m);
}
