//01EUCLID.CPP, Tim uoc so chung lon nhat cua hai so
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
 {clrscr();
  long m,n,t,m1,n1;
  printf("\nm, n =");scanf("%ld%ld",&m,&n);
  //Neu m<n thi doi vi tri m va n
  if(m<n) {t=m;m=n;n=t;}
  m1=m;n1=n;
  while(n>0)
   {t=n;
    n=m%n;
    m=t;
   }
  printf("\USCLN cua %ld va %ld la: %ld ",m1,n1,m);
  getch();
 }
