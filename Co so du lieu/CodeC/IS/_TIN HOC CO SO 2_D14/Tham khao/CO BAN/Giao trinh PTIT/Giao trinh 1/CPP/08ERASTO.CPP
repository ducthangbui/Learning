//08ERASTO.CPP, Sang Erastothen liet ke cac so nguyen to <=n
#include "stdio.h"
#include "conio.h"
#include "math.h"
//================
void main()
{clrscr();
 int n;
 printf("\nHay nhap so nguyen < 1500  n = ");scanf("%d",&n);
 int a[2000],i,j;
 for(i=2;i<=n;i++) a[i]=1;//Luc dau cho rang tat ca la nguyen to

 for(i=2;i<sqrt(float(n));i++)
  for(j=2;j<=n/i;j++) a[i*j]=0;//Neu k=i*j thi k khong phai la nguyen to

 printf("\nCac so nguyen to <= %d la:\n",n);
 for(i=2;i<=n;i++) if(a[i]) printf("%d  ",i);
 getch();
}
