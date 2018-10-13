#include<stdio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
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
void DoiCho(int &a,int &b)
{
	int tmp=a;
		a=b;
		b=tmp;
}
void SxTang(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
		if(a[i]>a[j]) DoiCho(a[i],a[j]);
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	scanf("%d ",a[i]);
}
main()
{
	int a[100],n;
	scanf("%d",&n);
	Nhap(a,n);
	/*Tim(a,n);
	if(kiemtratang(a,n)==1&&kiemtragiam(a,n)==1) printf("K tang k giam");
	else if(kiemtratang(a,n)==1) printf("Tang\n");
	else	if(kiemtragiam(a,n)==1) printf("Giam\n");*/
	SxTang(a,n);
	Xuat(a,n);
}
