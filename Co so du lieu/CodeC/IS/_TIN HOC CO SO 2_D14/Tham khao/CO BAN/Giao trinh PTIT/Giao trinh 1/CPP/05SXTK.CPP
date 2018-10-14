//05SXTK.CPP Nhap va sap xep danh sach
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
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
void xem(float a[],int n)
 {int i;
  printf("\n");
  for(i=0;i<n;i++) printf("%3.1f  ",a[i]);
 }
//====================================
int sapxeproi(float a[],int &n)
 {int i;
  for(i=0;i<n-1;i++)
   if(a[i]>a[i+1]) return(0);
  return(1);
 }
//====================================
int timnhiphan(float a[],int &n,float x)
 {int low,up,k;
  low=0;up=n-1;
  while(low<up)
   {k=(low+up)/2;
    if(a[k]==x) return(k);
    if(x<a[k]) up=k-1; else low=k+1;
   }
  return(-1);
 }
//====================================
int timnhiphandq(float a[],int low, int up, float x)
 {int k;
  if(low>up) return(-1);
  k=(low+up)/2;
  if(a[k]==x) return(k);
  if(x<a[k]) up=k-1; else low=k+1;
  return(timnhiphandq(a,low,up,x));
 }
//====================================
void main()
 {clrscr();
  float a[nmax],x;int n,k;char ch;
  while(1)
   {clrscr();
    printf("\n1. Nhap danh sanh");
    printf("\n2. Xem danh sach");
    printf("\n3. Sap xep danh sach");
    printf("\n4. Kiem tra sap xep chua");
    printf("\n5. Tim kiem nhi phan");
    printf("\n6. Tim kiem nhi phan de quy");
    printf("\nz. Ket thuc");
    printf("\nHay chon tu 1 -> z");
    ch=toupper(getch());
    if(ch=='Z') break;
    switch(ch)
     {case '1':nhap(a,n);break;
      case '2':xem(a,n);break;
      case '3':sapxep(a,n);break;
      case '4':if(sapxeproi(a,n))
		printf("\nSap xep roi");
		else printf("\nChua sap xep");
		break;
      case '5':printf("\nTim x = ");
	       scanf("%f",&x);
	       k=timnhiphan(a,n,x);
	       if(k>=0)
		printf("\nTim thay o vi tri a[%d] la %5.1f",k,a[k]);
		else
		printf("\nKhong tim thay!");
	       break;
      case '6':printf("\nTim x = ");
	       scanf("%f",&x);
	       k=timnhiphandq(a,0,n-1,x);
	       if(k>=0)
		printf("\nTim thay o vi tri a[%d] la %5.1f",k,a[k]);
		else
		printf("\nKhong tim thay!");
     }
  getch();
   }
 }
