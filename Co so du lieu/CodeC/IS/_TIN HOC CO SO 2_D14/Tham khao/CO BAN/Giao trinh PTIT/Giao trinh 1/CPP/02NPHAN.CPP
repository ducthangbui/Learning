//02NPHAN.CPP  Chuyen doi mot so thap phan sang nhi phan
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#define nmax 100
void main()
 {clrscr();
  int a[nmax];long n,i,j,k;
  printf("\nNhap so can doi sang so nhi phan: ");scanf("%ld",&n);
  i=0;
  while(n>0)
   {a[i]=n%2;
    n=n/2;
    i++;
   }
  i--;
  printf("\n");
  for(j=i;j>=0;j--) printf("%d",a[j]);
  getch();
 }
