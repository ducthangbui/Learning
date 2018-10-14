//18SVIEN3.CPP, Chuong trinh quan ly sinh vien 3.0
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
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
void xem()
 {clrscr();
  printf("\nDanh sach sinh vien trong lop:");
  int i;
  printf("\n\n  tt   Ho va ten            Tuoi");
  for(i=0;i<n;i++)
   printf("\n  %d    %-20s  %d ",i+1,ds[i].ten,ds[i].tuoi);
 }
//==================
void sapxepten()
 {int i,j,k;nhansu t;
  char s[20];
  for(i=0;i<n;i++)
   {strcpy(s,ds[i].ten);k=i;
    for(j=i+1;j<n;j++)
     if(strcmpi(ds[j].ten,s)<0) {k=j;strcpy(s,ds[j].ten);}
    if(k!=i) {t=ds[i];ds[i]=ds[k];ds[k]=t;}
   };
 }
//==================
void main()
 {char chon;
  while(1)
   {clrscr();
    printf("\n1. Nhap danh sach sinh vien");
    printf("\n2. Xem danh sach sinh vien");
    printf("\n3. Sap xep theo ten (khong phan biet chu hoa chu thuong)");
    printf("\nz. Ket thuc chuong trinh");
    printf("\n\nHay nhan phim 1,2 hoac z de chon muc can thuc hien: ");
    chon=getch();//chon se la ky tu vua nhan
    chon=toupper(chon);//Chuyen sang chu hoa
    if(chon=='Z') break;//Neu nhan z hoac Z thi ket thuc
    switch(chon)
     {case '1': nhap(n);break;
      case '2': xem();break;
      case '3': sapxepten();break;
     }
    gotoxy(1,25);
    printf("Nhan phim bat ky de tiep tuc");
    getch();

   }
 }
