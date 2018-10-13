#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
int Dx(int a[],int n)
{
	int c=0;
	int b=0;
	for(int i=0;i<n;i++)
	c=c*10+a[i];
	for(int j=n-1;j>=0;j--)
	b=b*10+a[j];
	if(c==b) return 1;
			 return 0;
}
int kiemtra(int a[],int n,int i) 
{ 
    int t=a[i]; 
    for (int j=0;j<n;j++) 
        if (t==a[j])return 0; 
    return 1; 
} 
int dem (int a[],int n,int i) 
{ 
    int t=a[i],j=0; 
    for (i=0;i<n;i++) 
    { 
        if (t==a[i]) j++; 
    } 
    return (j);   
} 
void KhacNhau(int a[],int n)
{
	int b[1000],j=0;
	printf("Cac so khac nhau la:");
	for(int i=0;i<n;i++)
	{
		if(dem(a,n,i)==1) 
		//b[j]=a[i],j++;
	//printf("Cac so khac nhau la:");
	//for(int k=0;k<j;k++)
		printf("%d ",a[i]);
	}
}
int ktrangto(int &n)
{
	int ktra=0;
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++)
	if (n%i==0) ktra++;
	if (ktra==0) return 1;
	else return 0;
}
int X(int a[],int n,int x)
{
	int i,j;
	int min=fabs(a[0]-x);
	for(i=1;i<n;i++)
	if(fabs(a[i]-x)<min) min=fabs(a[i]-x),j=i;
	printf("\nVi tri gan X nhat:%d\n",j);
	
}
main()
{
	int x,n,a[100];
	int ktra=0;
	printf("Nhap so phan tu cua mang:");
	scanf("%d",&n);
	Nhap(a,n);
	if(Dx(a,n)==1) printf("Day vua nhap la mang doi xung\n"); else printf("Day vua nhap khong phai la mang doi xung\n");
	KhacNhau(a,n);
	printf("\nNhap vao X:");
	scanf("%d",&x);
	for(int i=0;i<n;i++)
	{
	if(ktrangto(a[i])==1) X(a,n,x),ktra++;
	if(ktra!=0) exit(0);}
}
