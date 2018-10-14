//11HORNER.CPP Tim gia tri da thuc bac n tai x.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define nmax 100
//====================================
void nhap(float a[],int &n)
 {int i,j,k;
  printf("\nNhap bac cua da thuc: ");scanf("%d",&n);
  printf("\nNhap cac he so tu bac cao den thap:\n");
  for(i=n;i>=0;i--)
   {printf("Nhap  a[%d] = ",i); scanf("%f",&a[i]);
   }
  clrscr();
 }
//====================================
//Tinh p(x) = a[n]*(x mu n) + ... + a[1]*x +a[0]
float horner(float a[],int n,float x) //Tra ve gia tri da thuc tai x
 {int i;float s;
  s=a[n];
  for(i=n-1;i>=0;i--) s=s*x+a[i];
  return(s);
 }
//====================================
void view(float a[],int n)
 {int i;
  printf("\nCac he so da thuc tu mu bac cao den thap:\n");
  for(i=n;i>=0;i--) printf("%3.1f  ",a[i]);
 }
//====================================
void main()
 {clrscr();
  float a[nmax],x;int n,k;
  nhap(a,n);
  printf("\nCac he so cua da thuc tu bac cao den thap la:");
  view(a,n);
  printf("\nHay nhap gia tri can tinh gia tri da thuc, x = ");scanf("%f",&x);
  printf("\nGia tri da thuc tai x = %.1f la %.1f",x,horner(a,n,x));
  getch();
 }
