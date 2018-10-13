#include<stdio.h>
#include<stdlib.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
int KiemTraTang(int a[],int n)
{
	int ktra=1;
	for(int i=0;i<n;i++)
	if(a[i]>a[i+1])
	{
		ktra=0;
		break;
	}
	return ktra;
}
void Vitri(int a[],int n)
{
	int i,ktra=1;;
	for(i=0;i<n;i++)
	{
	if(a[i]>a[i+1]) printf("Vi tri:%d",i+1),ktra=0;
	if(ktra==0) exit(0);}
	
}
main()
{
	int a[100],n;
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	if(KiemTraTang(a,n)==1) printf("Day dc sap xep tang\n");
	else 
	{
	printf("Day k dc sap xep tang\n");
	Vitri(a,n);}
}
