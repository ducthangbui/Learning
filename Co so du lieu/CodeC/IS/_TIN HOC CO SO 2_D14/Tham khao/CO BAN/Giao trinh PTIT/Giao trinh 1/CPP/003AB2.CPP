//003AB2.CPP  Nhap 2 so thuc. Tinh tong, hieu, tich, thuong.
#include <stdio.h>
#include <conio.h>
void main()
 {clrscr();
  float a,b,tong,tich,hieu,thuong;
  printf("\nNhap 2 so a,b = ");
  scanf("%f%f",&a,&b);
  tong=a+b;tich=a*b;hieu=a-b;thuong=a/b;
  printf("Tong cua 2 so  %4.1f  va  %4.1f  la  %4.1f",a,b,tong);
  //Hay in ra tich, hieu va thuong
  getch();
 }