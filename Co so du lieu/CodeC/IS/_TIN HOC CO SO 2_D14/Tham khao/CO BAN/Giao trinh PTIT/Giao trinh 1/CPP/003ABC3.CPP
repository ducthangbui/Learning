//003ABC3.CPP  Tim cac tam giac vuong co canh la so nguyen khong lon hon 20
#include <stdio.h>
#include <conio.h>
void main()
 {clrscr();
  int a,b,c;
  for(a=1;a<=20;a++)
  for(b=1;b<=20;b++)
  for(c=1;c<=20;c++)
   if(b*b+c*c==a*a)
    printf("\n %d   %d   %d",a,b,c);
  gotoxy(2,24);
  printf("Xem xong nhan phim bat ky de ket thuc");
  getch();
 }
/*Bai tap:Tim cac tam giac vuong co canh la so nguyen khong lon hon 100
*/