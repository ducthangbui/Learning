//21SVIEN6.CPP, Chuong trinh quan ly sinh vien 6.0
//Cai dat bang mang dong
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
nhansu *ds;int n=0;
//Mang dslop[] la danh sach sinh vien trong lop, n la so sinh vien
//==================
void nhap(int &n)
 {ds = new nhansu[nmax];
  clrscr();
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
//Tim kiem ten, neu tim thay thi tra ve vi tri tim thay
int timkiemten(char *pten)
 {int i;
  for(i=0;i<n;i++)
   if(strcmpi(pten,ds[i].ten)==0) return(i);
  return(-1);
 }
//==================
void main()
 {char chon;char mten[20]; int k;
  while(1)
   {clrscr();
    printf("\n1. Nhap danh sach sinh vien");
    printf("\n2. Xem danh sach sinh vien");
    printf("\n3. Sap xep theo ten (khong phan biet chu hoa chu thuong)");
    printf("\n4. Tim kiem theo ten (khong phan biet chu hoa chu thuong)");
    printf("\nz. Ket thuc chuong trinh");
    printf("\n\nHay nhan phim 1,2 hoac z de chon muc can thuc hien: ");
    chon=getch();//chon se la ky tu vua nhan
    chon=toupper(chon);//Chuyen sang chu hoa
    if(chon=='Z') break;//Neu nhan z hoac Z thi ket thuc
    switch(chon)
     {case '1': nhap(n);break;
      case '2': xem();break;
      case '3': sapxepten();break;
      case '4': fflush(stdin);printf("\nHay nhap ten can tim: ");gets(mten);
		k=timkiemten(mten);
		if(k==-1) printf("\nKhong tim thay");
		else
		printf("\Ten tim thay la: %s", ds[k].ten);
		break;
     }
    gotoxy(1,25);
    printf("Nhan phim bat ky de tiep tuc");
    getch();
   }
 }
