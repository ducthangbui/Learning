//005PTB2.CPP  Giai phuong trinh bac 2
#include <stdio.h>
#include <conio.h>
#include <math.h>
void nhap(float &a,float &b,float &c)
 {printf("\nNhap 3 so a, b, c = ");
  scanf("%f%f%f",&a,&b,&c);
 }
float delta(float a,float b,float c)
 {return(b*b-4*a*c);
 }
//nghiem=0 la vo nghiem, =1 la co nghiem kep la x0, =2 co 2 nghiem x1 va x2
void loigiai(float a,float b,float c,int &nghiem,float &x0,float &x1,float &x2)
 {float d=delta(a,b,c);
  if(d<0) nghiem=0;
  if(d==0) {nghiem=1;x0=-b/(2*a);}
  if(d>0) {nghiem=2;x1=(-b+sqrt(d))/(2*a);x2=(-b-sqrt(d))/(2*a);}
 }
void main()
 {clrscr();
  float a,b,c,x0,x1,x2;int nghiem;
  nhap(a,b,c);
  loigiai(a,b,c,nghiem,x0,x1,x2);
  switch(nghiem)
   {case 0:printf("\nVo nghiem");break;
    case 1:printf("\nNghiem kep x0 = %5.1f",x0);break;
    case 2:printf("\nCo 2 nghiem x1 = %5.1f, x2 = %5.1f",x1,x2);break;
   }
  gotoxy(2,24);
  printf("Xem xong nhan phim bat ky de ket thuc");
  getch();
 }
/*Bai tap:Khai bao cac bien a,b,c,nghiem,x0,x1,x2 la bien toan cuc
  roi viet lai cac ham tren day
*/