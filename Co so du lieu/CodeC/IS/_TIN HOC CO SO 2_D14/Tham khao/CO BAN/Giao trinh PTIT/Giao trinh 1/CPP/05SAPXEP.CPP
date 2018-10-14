//05SAPXEP.CPP Nhap va sap xep danh sach
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
void sapxep(float a[],int n)
 {int i,j,k;float t;
  for(i=0;i<n;i++)
   {t=a[i];k=i;
    for(j=i+1;j<n;j++)
     if(a[j]<t) {t=a[j];k=j;}
   if(k!=i) {t=a[i];a[i]=a[k];a[k]=t;}
   }
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
  float a[nmax];int n;
  nhap(a,n);
  printf("\nDanh sach chua sap xep la:");
  view(a,n);
  printf("\nDanh sach da sap xep la:");
  sapxep(a,n);
  view(a,n);
  getch();
 }
