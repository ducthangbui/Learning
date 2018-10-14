//004100T.CPP  Tram trau tram co
#include <stdio.h>
#include <conio.h>
void main()
 {clrscr();
  int dung,nam,gia;
  for(dung=0;dung<=20;dung++)
  for(nam=0;nam<=33;nam++)
  for(gia=0;gia<=100;gia++)
   if(dung*5+nam*3+gia/3==100 && gia%3==0)
    printf("\n %d   %d   %d",dung,nam,gia);
  gotoxy(2,24);
  printf("Xem xong nhan phim bat ky de ket thuc");
  getch();
 }
/*Bai tap:Cho hien dong tieu de  Dung  Nam   Gia, sau do la cac hang chua
loi giai. Moi lan day man hinh 24 dong thi dung lai de xem, sau do nhan phim
de xem tiep.
*/