//003ABC2.CPP  Nhap 3 so thuc. Kiem tra xem chung co phai la 3 canh
//cua tam giac khong; sau do kiem tra xem chung co phai la 3 canh tam
//giac vuong khong
#include <stdio.h>
#include <conio.h>
void main()
 {clrscr();
  float a,b,c;
  printf("\nNhap 3 so a,b,c = ");
  scanf("%f%f%f",&a,&b,&c);
  if(a+b>c && a+c>b && b+c>a)
     printf("\nChung la 3 canh cua mot tam giac");
     else
     printf("\nChung khong phai la 3 canh cua mot tam giac");
  if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
     printf("\nChung la 3 canh cua mot tam giac vuong");
     else
     printf("\nChung khong phai la 3 canh cua mot tam giac vuong");
  getch();
 }
/*Bai tap: Hay nhap 3 so thuc, kiem tra neu chung khong phai la 3 canh
cua mot tam giac thi thong bao va ket thuc, con neu la 3 canh cua tam giac thi
thong bao, sau do kiem tra tiep co phai la 3 canh cua tam giac vuong khong,
neu co thi thong bao.
*/