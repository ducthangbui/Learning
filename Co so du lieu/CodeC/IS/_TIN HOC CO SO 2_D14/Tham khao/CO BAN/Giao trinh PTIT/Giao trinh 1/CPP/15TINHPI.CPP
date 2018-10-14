//15TINHPI.CPP, Tinh so pi
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
//==================
double tinhpi()
 {double tong,sh,epsi,dau;
  int n;
  epsi=0.0001;
  tong=0;
  sh=1;
  dau=1;
  n=0;
  while(fabs(sh)>epsi)
   {tong=tong+sh;
    n++;
    dau=-dau;
    sh=dau/(2*n+1);
   }
  return(tong*4);
 }
//================
void main()
 {clrscr();
  printf("\n Pi = %f",tinhpi());
  getch();
 }
