//24DSF1.CPP
//Chuong trinh quan ly sinh vien tren tep nhi phan
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <ctype.h>
#include <string.h>
#include <dos.h>
#define false 0
#define true 1
#include "dir.h"
struct sv {char ten[25];int tuoi;};
FILE* f;char tentep[]="sv.dat";
int ssv,current,recsize=sizeof(sv);
void khoitao();
void nhap();
void xem();
void sapxep();
int timkiem();
//================================
int cokhong(char *st);
sv getrec(int n);//Lay ban ghi thu n,(ban ghi dau tien la 0)
void gotorec(int n);//Chuyen den truoc ban ghi thu n
void doicho(int i,int j);//Doi dong thu i cho dong j
char* rtrim(char *s);//Bo cac ky tu trong cuoi chuoi
//====================================================
//====================================================
void main()
{char chon;
 while(true)
  {clrscr();
   printf("\nF1. Khoi tao");
   printf("\nF2. Nhap");
   printf("\nF3. Xem");
   printf("\nF4. Sap xep");
   printf("\nF5. Tim kiem");
   printf("\nF10.Ket thuc");
   printf("\n    Nhan phim F1 - F10 de chon");
   chon=getch();
   if(chon==0) chon=getch();
   if(chon==68) break;
   switch(chon)
    {case 59: khoitao();break;//F1
     case 60: nhap();break;   //F2
     case 61: xem();break;    //F3
     case 62: sapxep();break; //F4
     case 63: if(!timkiem()) printf("\nKhong tim thay");break;//F5
    }
   gotoxy(50,24);
   printf("Nhan phim bat ky de tiep tuc");
   getch();
  }
}
//==================================================
void khoitao()
 {ffblk f1;int i;
  if(findfirst("svb.dat",&f1,0)==0)
    {if(cokhong("Tep da ton tai, ghi de khong?(C/K)"))
      f=fopen("svb.dat","wb");
    }
    else
    f=fopen("svb.dat","wb");
  fclose(f);
  f=fopen("svb.dat","r+b");
  fseek(f,0,2);
  ssv=ftell(f)/recsize;
 }
//========================================
void nhap()
 {if(f==NULL) khoitao();
  fseek(f,0,2);
  int i,mm;sv tmp;
  printf("\nNhap bao nhieu nguoi?");scanf("%d",&mm);
  for(i=0;i<mm;i++)
   {printf("\nNhap nhan vien thu %d :",ssv+i+1);
    fflush(stdin);
    printf("\nTen: ");gets(tmp.ten);
    printf("Tuoi: ");scanf("%d",&tmp.tuoi);
    fwrite(&tmp,recsize,1,f);
   }
  ssv+=mm;
  current=ssv-1;
 }
//=============================================
void xem()
 {if(f==NULL) khoitao();
  fseek(f,0,0);//rewind(f);
  int i;sv tmp;
  printf("\nDanh sach sinh vien:");
  printf("\nTen       tuoi");
  while(fread(&tmp,recsize,1,f)>0)
   {printf("\n%-20s %d",tmp.ten,tmp.tuoi);
   }
 }
//========================================
void sapxep()
 {int i,j,k,mtuoi;
  for(i=0;i<ssv-1;i++)
   {k=i;
    for(j=i+1;j<ssv;j++)
     {if(getrec(j).tuoi<getrec(k).tuoi) k=j;
     }
    if(k!=i) doicho(i,k);
   }
 }
//====================================
int timkiem()
 {if(f==NULL) khoitao();
  fseek(f,0,0);//rewind(f);
  int i;sv tmp;
  char mten[20];
  fflush(stdin);
  cout<<endl<<"Tim ten: ";gets(mten);
  i=0;
  while(fread(&tmp,recsize,1,f)>0)
   {if(strcmp(rtrim(tmp.ten),mten)==0)
     {printf("\nSinh vien tim thay la:\n");
      printf("\n%-20s %d",tmp.ten,tmp.tuoi);
      current=i;return(1);
     };
    i++;
   }
  return(0);
 }
//==================================================
int cokhong(char *st)
 {printf("\n%s",st);
  char ch=toupper(getche());
  if(ch=='C') return(1);else return(0);
 }
//==================================================
//Lay ban ghi thu n,(ban ghi dau tien la 0)
sv getrec(int n)
{sv tmp;
 fseek(f,n*recsize,0);//Nhay qua ban ghi thu n-1
 fread(&tmp,recsize,1,f);
 return(tmp);
};
//====================================================
//Chuyen den truoc ban ghi thu n
void gotorec(int n)
{fseek(f,n*recsize,0);//Nhay qua ban ghi thu n-1
 //bay gio con tro da dung truoc ban ghi thu n
};
//========================================================
void doicho(int i,int j)
 {sv p1,p2;
  p1=getrec(i);
  p2=getrec(j);
  gotorec(i);
  fwrite(&p2,recsize,1,f);
  gotorec(j);
  fwrite(&p1,recsize,1,f);
 }
//====================================================
char* rtrim(char *s)
 {int i,n=strlen(s)-1;
  i=n;
  while(!isalpha(s[i])) i--;
  if(isalpha(s[i])) s[i+1]='\0';
  return(s);
 };
//====================================================
