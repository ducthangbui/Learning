//09TimMax.CPP Tim Max trong day phan tu
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
int timmax(float a[],int n) //Tra ve vi tri k ma a[k] la max
 {int i,k;float max;
  max=a[0];k=0;
  for(i=1;i<n;i++)
    if(a[i]>max) {max=a[i];k=i;}
  return(k);
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
  float a[nmax];int n,k;
  nhap(a,n);
  printf("\nDanh sach da nhap la:");
  view(a,n);
  k=timmax(a,n);
  printf("\nPhan tu cuc dai la a[%d] = %.1f",k,a[k]);
  getch();
 }
