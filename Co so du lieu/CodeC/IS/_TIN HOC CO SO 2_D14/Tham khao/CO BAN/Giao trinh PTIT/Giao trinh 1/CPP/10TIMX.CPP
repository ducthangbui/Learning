//10TimX.CPP Tim X trong day phan tu
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define nmax 100
//====================================
void nhap(float a[],int &n)
 {int i,j,k;
  printf("\nNhap co cua mang: ");scanf("%d",&n);
  printf("\n");
  for(i=0;i<n;i++)
   {printf("Nhap  a[%d] = ",i); scanf("%f",&a[i]);
   }
  clrscr();
 }
//====================================
int timkiem(float a[],int n,float x) //Tra ve vi tri k ma a[k] la a[k]=x
 {int i;
  for(i=0;i<n;i++)
    if(a[i]==x) return(i);
  return(-1);
 }
//====================================
void view(float a[],int n)
 {int i;
  printf("\n");
  for(i=0;i<n;i++) printf("%3.1f  ",a[i]);
 }
//====================================
void main()
 {clrscr();
  float a[nmax],x;int n,k;
  nhap(a,n);
  printf("\nDanh sach da nhap la:");
  view(a,n);
  printf("\nHay nhap gia tri can tim x = ");scanf("%f",&x);
  k=timkiem(a,n,x);
  if(k>=0)
   printf("\nPhan tu tim thay la la a[%d] = %.1f",k,a[k]);
   else
   printf("\nKhong tim thay phan tu %f trong day tren",x);
  getch();
 }
