//16SVf_a.CPP, Chuong trinh quan ly sinh vien 1.0 cho ket qua tren tep
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
void nhap(int &n)
 {clrscr();
  printf("\nHay nhap so sinh vien trong lop: ");scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
   {printf("\nNhap thong tin cho nguoi thu %d:",i+1);
    printf("\nTen : ");fflush(stdin);gets(ds[i].ten);
    printf("Tuoi: ");scanf("%d",&ds[i].tuoi);
   }
 }
//==================
void ghitep(char tentep[12])
 {FILE *f = fopen(tentep,"wt");
  fprintf(f,"\nDanh sach sinh vien");
  int i;
  fprintf(f,"\n\n  tt   Ho va ten            Tuoi");
  for(i=0;i<n;i++)
   fprintf(f,"\n  %d    %-20s  %d ",i+1,ds[i].ten,ds[i].tuoi);
   fclose(f);
 }
//==================
void xemtep(char tentep[12])
 {FILE *f = fopen(tentep,"rt");
  char s[255];
  while(fgets(s,255,f)!=NULL)
   puts(s);
  fclose(f);
 }
//==================
void main()
 {char chon;
  while(1)
   {clrscr();
    printf("\n1. Nhap danh sach sinh vien");
    printf("\n2. Ghi danh sach sinh vien len tep");
    printf("\n3. Xem tep");
    printf("\nz. Ket thuc chuong trinh");
    printf("\n\nHay nhan phim 1,2 hoac z de chon muc can thuc hien: ");
    chon=getch();//chon se la ky tu vua nhan
    chon=toupper(chon);//Chuyen sang chu hoa
    if(chon=='Z') break;//Neu nhan z hoac Z thi ket thuc
    switch(chon)
     {case '1': nhap(n);break;
      case '2': ghitep("VUT.TXT");break;
      case '3': xemtep("VUT.TXT");break;
     }
    gotoxy(1,25);
    printf("Nhan phim bat ky de tiep tuc");
    getch();

   }
 }
