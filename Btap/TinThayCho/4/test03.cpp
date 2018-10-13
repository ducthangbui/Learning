#include<stdio.h>
void Them(int a[], int &n, int vt, int &x)
{
	if (vt >= 0 && vt <= n)
	{
		for (int i = n; i > vt; i--)
			a[i] = a[i - 1];
	
		a[vt] = x;
		n++;
	}
}
void Nhap(int a[],int n)
{
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
main()
{
	int n,a[100];
	scanf("%d",&n);
	Nhap(a,n);
	int x,vt;
	scanf("%d%d",&x,&vt);
	Them(a,n,vt,x);//THem(a,n,vt+1,x) de them vao ben phai
	Xuat(a,n);
}
