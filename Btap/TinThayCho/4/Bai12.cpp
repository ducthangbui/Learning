#include<stdio.h>
#include<stdlib.h>
#include<ctime>
void RandomArr(int a[],int n)
{
	srand((int)(time (0)));
	for(int i=0;i<n;i++)
	a[i]=rand()%n;
}
void Doicho(int &a,int &b)
{
	int tmp=a;
		a=b;
		b=tmp;
}
void SxNoiBot(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
	if(a[i]>=a[j]) Doicho(a[i],a[j]);
}
int kiemtra(int a[],int n,int i) 
{ 
    int t=a[i]; 
    for (int j=0;j<i;j++) 
        if (t==a[j])return 0; 
    return 1; 
} 
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
main()
{
	int n,a[100];
	printf("Nhap vao so phan tu mang:");
	scanf("%d",&n);
	RandomArr(a,n);
	printf("Mang ngau nhien la: ");
	XuatMang(a,n);
	printf("\nMang sau khi da sap xep la: ");
	SxNoiBot(a,n);
	XuatMang(a,n);
	printf("\nMang da loc la: ");
	for(int i=0;i<n;i++)
	if(kiemtra(a,n,i)) printf("%d ",a[i]);
}
