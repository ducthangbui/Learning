#include<stdio.h>
void Nhap(int a[],int &n)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
/*void Xoa(int a[], int &n, int vt)
{
	if (vt >= 0 && vt < n)
	{
		for(int i=vt;i<n-1; i++)
			a[i] = a[i + 1];
	
		n--;
	}
}*/
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
main()
{
	int nb,a[100];
	//scanf("%d",&n);
	Nhap(a,nb);
	//int vt;
	//scanf("%d",&vt);
	//Xoa(a,n,vt);
	Xuat(a,nb);
}
