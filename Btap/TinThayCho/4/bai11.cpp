#include<stdio.h>
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
    for (int j=0;j<i;j++) 
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
main()
{
	int n,a[100];
	printf("Nhap so phan tu cua mang:");
	scanf("%d",&n);
	Nhap(a,n);
	for(int i=0;i<n;i++)
	if(kiemtra(a,n,i)) printf("%d xuat hien %d lan\n",a[i],dem(a,n,i));
}
