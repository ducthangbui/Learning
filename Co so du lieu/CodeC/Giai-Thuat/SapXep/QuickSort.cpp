#include<stdio.h>
void Nhap(int a[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Nhap vao phan tu thu %d:",i+1);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n)
{
	int i;
	for (i=0;i<n;i++)
	printf("%2d ",a[i]);
}
void QuickSort(int a[],int l,int r)
{
	int i,j,x,w;
	i=l;
	j=r;
	x=a[(l+r)/2];
	while(i<=j)
	{
		while (a[i]<x) i++;
		while (a[j]>x) j--;
		//printf("%d %d| ",i,j);
		if (i<=j)
		{
			w=a[i];
			a[i]=a[j];
			a[j]=w;
			i++;
			j--;
		}
		
		//printf("%d %d; \n",i,j);
	}
	//printf("l=%d r=%d|| \n",l,r);
	if (l<j) QuickSort(a,l,j);
	if (i<r) QuickSort(a,i,r);
}
main()
{
	int a[100],n;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	//printf("Nhap vao vi tri dau:");
	//scanf("%d",&l);
	//printf("Nhap vao vi tri cuoi:");
	//scanf("%d",&r);
	//QuickSort(a,0,n-1);
	printf("Mang da dc sx la:\n");
	QuickSort(a,0,n-1);
	Xuat(a,n);
}
