//17SVIEN2.CPP, Chuong trinh quan ly sinh vien 2.0
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define nmax 100
//nmax la co toi da cua mang danh sach sinh vien
//==================
struct nhansu
 {char ten[20];
  int tuoi;
 };
nhansu ds[nmax];int n=0;
//Mang dslop[] la danh sach sinh vien trong lop, n la so sinh vien
//==================
void defwindow(int cot1,int dong1,int cot2,int dong2,int maunen, int mauchu)
 {window(cot1,dong1,cot2,dong2);
  textbackground(maunen);
  textcolor(mauchu);
  clrscr();
 }
//==================
void normalscreen()
 {textmode(C80);
  window(1,1,80,25);
  textbackground(BLUE);
  textcolor(WHITE);
  clrscr();
 }
//==================
void nhap(int &n)
 {normalscreen();
  printf("\nHay nhap so sinh vien trong lop: ");scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
   {printf("\nNhap thong tin cho nguoi thu %d:",i+1);
    printf("\nTen : ");fflush(stdin);gets(ds[i].ten);
    printf("Tuoi: ");scanf("%d",&ds[i].tuoi);
   }
 }
//==================
void xem()
 {//normalscreen();
  defwindow(1,1,80,25,MAGENTA,BLUE);
  defwindow(3,2,78,24,CYAN,BLUE);
  defwindow(4,2,77,24,CYAN,BLUE);

  //\n co nghia la xuong dong, voi printf thi ve dau dong (carriage-return)
  //nhung voi cprint can phai co them \r  la lenh tro ve dau dong
  cprintf("\r\nDanh sach sinh vien trong lop:");
  int i;
  cprintf("\r\n\n  tt   Ho va ten            Tuoi");
  for(i=0;i<n;i++)
   cprintf("\r\n  %d    %-20s  %d ",i+1,ds[i].ten,ds[i].tuoi);
  gotoxy(1,22);
  cprintf("Nhan phim bat ky de tiep tuc");
  getch();
 }
//==================
void main()
 {char chon;
  while(1)
   {normalscreen();
    printf("\n  1. Nhap danh sach sinh vien");
    printf("\n  2. Xem danh sach sinh vien");
    printf("\n  z. Ket thuc chuong trinh");
    printf("\n\n   Hay nhan phim 1,2 hoac z de chon muc can thuc hien: ");
    chon=getch();//chon se la ky tu vua nhan
    chon=toupper(chon);//Chuyen sang chu hoa
    if(chon=='Z') break;//Neu nhan z hoac Z thi ket thuc
    switch(chon)
     {case '1': nhap(n);break;
      case '2': xem();
     }

   }
 }
