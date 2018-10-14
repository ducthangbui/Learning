//003AB1.CPP  Nhap 2 so nguyen. Tinh tong, hieu, tich, thuong.
#include <stdio.h>
#include <conio.h>
void main()
 {clrscr();
  int a,b,tong,tich,hieu,thuong;
  printf("\nNhap 2 so a,b = ");
  scanf("%d%d",&a,&b);
  tong=a+b;tich=a*b;hieu=a-b;thuong=a/b;
  printf("Tong cua 2 so  %d  va  %d  la  %d",a,b,tong);
  //Hay in ra tich, hieu va thuong
  getch();
 }