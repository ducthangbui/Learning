//23DSLK2.CPP Cai dat bai toan quan ly sinh vien bang danh sach lien ket
/*
 Con tro phead se chi vao ban ghi dau tien, tuc la ban ghi chua sinh vien
 dau tien. Truong next cua cac ban ghi chi den ban ghi tiep theo. Truong
 next cua ban ghi cuoi cung chi den con tro NULL.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <dos.h>
#define false 0
#define true 1
struct kthang {int thang,nam;};
struct nhansu {char ten[20];kthang tsinh;int tuoi;nhansu* next;};
int snv;nhansu *phead,*pcurrent;
void khoitao();
void nhap();
void xem();
void sapxep();
void sapxep2();
void main()
{const int F1=59,F2=60,F3=61,F4=62,F10=68;
 char chon;
 while(true)
  {clrscr();
   printf("\nF1. Khoi tao");
   printf("\nF2. Nhap");
   printf("\nF3. Xem");
   printf("\nF4. Sap xep");
   printf("\nF10.Ket thuc");
   printf("\n    Nhan phim F1 - F10 de chon");
   chon=getch();
   if(chon==0) chon=getch();
   if(chon==F10) break;
   switch(chon)
    {case F1: khoitao();break;
     case F2: nhap();break;
     case F3: xem();break;
     case F4: sapxep();break;
    }
   gotoxy(50,24);
   printf("Nhan phim bat ky de tiep tuc");
   getch();
  }
}
//========================================
void khoitao()
 {phead=NULL;
  snv=0;pcurrent=NULL;
 };
//========================================
void nhap()
 {int i,mm;
  nhansu *p1,*p, *tmp;
  p=p1=phead;
  while(p!=NULL)
   {p1=p;
    p=p->next;
   }
  cout<<endl<<"Nhap bao nhieu nguoi?";cin>>mm;
  for(i=0;i<mm;i++)
   {tmp=new nhansu;tmp->next=NULL;
    cout<<endl<<"Nhap nhan vien thu "<<snv+i<<": ";
    cout<<endl<<"Ten: ";gets(tmp->ten);
    cout<<endl<<"Tuoi: ";cin>>tmp->tuoi;
    cout<<endl<<"Thang: ";cin>>tmp->tsinh.thang;
    cout<<endl<<"Nam: ";cin>>tmp->tsinh.nam;
    if(p1==NULL)
     {p1=phead=tmp;}
      else
      {p1->next=tmp;p1=tmp;}

   }
  snv+=mm;
  pcurrent=p1;
 }
//========================================
void xem()
 {int i;
  cout<<endl<<"Danh sach nhan vien:";
  cout<<endl<<"Ten      tuoi  thang   nam";
  nhansu *p=phead;
  while(p!=NULL)
   {cout<<endl<<p->ten<<"       "<<p->tuoi<<"    "<<p->tsinh.thang<<"    "<<p->tsinh.nam;
    p=p->next;
   }
 }
//========================================
void sapxep()
 {if(snv<2) return;
  nhansu *p,*p1,*p2,*ptmp,tmp;int mtuoi;
  p=p1=p2=phead;
  //pt truoc p,p1t truoc p1
  while(p1!=NULL)
   {p=p1;
    p2=p1->next;
    while(p2!=NULL)
     {//if(long(p2->tsinh.nam*100+p2->tsinh.thang)<long(p->tsinh.nam*100+p->tsinh.thang)) p=p2;
      if(p2->tsinh.nam*100+p2->tsinh.thang<p->tsinh.nam*100+p->tsinh.thang) p=p2;
      p2=p2->next;
     }
    if(p!=p1)
     {tmp=*p1;ptmp=p1->next;
      *p1=*p;p1->next=ptmp;
      ptmp=p->next;*p=tmp;
      p->next=ptmp;
     }
    p1=p1->next;
   }
 }
//========================================
//========================================
void sapxep2()
 {if(snv<2) return;
  nhansu *p,*pt,*p1,*p1t,*p2,*p2t,*ptmp,tmp;int mtuoi;
  p1t=p1=phead;
  //pt truoc p,p1t truoc p1
  while(p1!=NULL)
   {pt=p1t;
    p=p1;
    p2t=p1;
    p2=p1->next;
    while(p2!=NULL)
     {if(p2->tuoi<p->tuoi) {pt=p2t;p=p2;}
      p2t=p2;
      p2=p2->next;
     }
    if(p==p1)
     {p1t=p1;
      p1=p1->next;
      continue;
     }
    if(p1==phead)

     {if(p1->next==p)//p va p1 lien nhau
	{ptmp=p->next;
	 phead=p;p->next=p1;p1->next=ptmp;
	}
	else
	{ptmp=p->next;
	 phead=p;p->next=p1->next;pt->next=p1;p1->next=ptmp;
	}
     }
     else
     {if(p1->next==p)//p va p1 lien nhau
	{ptmp=p->next;
	 p1t->next=p;p->next=p1;p1->next=ptmp;
	}
	else
	{ptmp=p->next;
	 p1t->next=p;p->next=p1->next;pt->next=p1;p1->next=ptmp;
	}
     }
    p1=p;
    p1t=p1;
    p1=p1->next;
   }
 }
