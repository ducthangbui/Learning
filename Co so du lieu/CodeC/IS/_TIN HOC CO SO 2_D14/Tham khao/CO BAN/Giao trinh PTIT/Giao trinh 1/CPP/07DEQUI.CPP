//07DEQUI.CPP, Cac chuong trinh de quy
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
//===============================
long gt(int n)
 {return((n==0||n==1)?1:n*gt(n-1));
 }
//===============================
long fibo(int n)
 {return((n==0||n==1)?n:fibo(n-1)+fibo(n-2));
 }
//===============================
int uscln(int u,int v)
 {if(u==v) return u;
  else
  if(u<v)
   return(uscln(u,v-u));
   else
   return(uscln(u-v,v));
 }
//===============================
void THAPHN(int n,char A,char B,char C)
 {
  if(n==1)
   {printf("\n%c ====> %c",A,B);return;
   };
  THAPHN(n-1,A,C,B);
  THAPHN(1,A,B,C);
  THAPHN(n-1,C,B,A);
 };
//===============================
void main()
 {clrscr();int x,y;
  int m,n,m1,n1,u;
  printf("\nTinh n! voi n = ");scanf("%d",&n);
  printf("\n%d! = %ld",n,gt(n));

  printf("\n\nTinh so Fibonacci voi n = ");scanf("%d",&n);
  printf("\nSo Fibonacci f(%d) = %ld",n,fibo(n));

  printf("\n\nTim USCLN cua m va n (nhap m va n) = ");scanf("%d%d",&m,&n);
  m1=m;n1=n;
  u=uscln(m,n);
  printf("\nUSCLN cua  %d  va  %d  la %d",m1,n1,u);
  printf("\nNhan phim bat ky de tiep tuc...");
  getch();
  printf("\n");
  x=wherex();y=wherey();
  while(1)
   {gotoxy(x,y);
    printf("\nHay nhap so dia n can chuyen tren thap Ha Noi (n<=7): ");
    scanf("%d",&n);
    if(n>7) {printf("\nSo dia phai <= 7 ");delay(1500);continue;}
    break;
   }
  clrscr();
  printf("\Qua trinh chuyen dia duoc thuc hien nhu sau:");
  THAPHN(n,'1','2','3');
  getch();
 }

