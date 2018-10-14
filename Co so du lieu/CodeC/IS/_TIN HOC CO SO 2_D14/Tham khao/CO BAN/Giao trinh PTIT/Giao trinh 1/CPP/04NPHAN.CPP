//04NPHAN.CPP, Chuyen doi mot so thap phan sang so co so 11
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define nmax 20
void main()
 {clrscr();
  int a[nmax];long n,i,j,k;
  printf("\nNhap so can doi sang so co so 11: ");scanf("%ld",&n);
  i=0;
  while(n>0)
   {a[i]=n%11;
    n=n/11;
    i++;
   }
  i--;
  printf("\n");
  for(j=i;j>=0;j--)
   if(a[j]==10) printf("A");else printf("%d",a[j]);
  getch();
 }
