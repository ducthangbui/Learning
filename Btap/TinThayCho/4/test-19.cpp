#include<stdio.h>
void nhap(int a[], int &n)
{
printf("\n nhap so phan tu"); scanf("%d",&n);
for ( int i =0;i<n; i++)
{ printf("\nhap phan tu a[%d] = ",i); scanf("%d",&a[i]);}
}
void tangdainhat( int a[], int n)
{ int b[100],d;
for ( int i = 0; i<n; i++)
{d=1;
for ( int j = i; j<n-1; j++)
if (a[j] <= a[j+1]) d++;
else break;
b[i] = d; }
int max = b[0];
for ( int i = 0; i<n; i++)
if (b[i]> max) max = b[i];
for ( int i=0; i<n; i++)
if (b[i]== max) printf("%d %d \n", i, b[i]);
}
main()
{ int a[100],n;
nhap(a,n);
tangdainhat(a,n);
}
