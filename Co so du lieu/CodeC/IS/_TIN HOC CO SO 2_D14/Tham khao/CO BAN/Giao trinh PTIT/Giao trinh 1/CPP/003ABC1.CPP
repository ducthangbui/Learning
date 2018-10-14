//003ABC1.CPP  Nhap 3 so thuc. Tim max cua chung.
#include <stdio.h>
#include <conio.h>
void main()
 {clrscr();
  float a,b,c,max;
  printf("\nNhap 3 so a,b,c = ");
  scanf("%f%f%f",&a,&b,&c);
  max=a;
  if(b>max) max=b;
  if(c>max) max=c;
  printf("Max cua 3 so  %4.1f, %4.1f  va  %4.1f  la  %4.1f",a,b,c,max);
  //Hay tinh min
  getch();
 }