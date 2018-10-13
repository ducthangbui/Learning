#include<stdio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
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
	scanf("%d",&n);
	Nhap(a,n);
	for(int i=0;i<n;i++)
	//if (kiemtra(a,n,i))printf("%d\n",dem(a,n,i));
	if(dem(a,n,i)==1) printf("%d",a[i]);
 } 
