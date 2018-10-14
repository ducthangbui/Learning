#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct sinhvien
{
char ms[5];
char name[80];
float diem;
struct sinhvien *next;
}*first=NULL,*last=NULL;

FILE *fpt;
int i=0;
/////////////////////////////////////////

void xoads()
{
struct sinhvien *ptr;
 while(first!=NULL)
 {
 ptr=first;
 first=first->next;
 free(ptr);
 }
first=last=NULL;
}
///////////////////////////////////////

void nhapdsmoi()
{
struct sinhvien sv;
char maso[5],chon;
printf("ban co muon xoa danh sach cu va viet lai danh sach moi?(C/K):");
do
{
chon=toupper(getchar());
}while(chon!='C' && chon!='K');

flushall();
if(chon=='C')
{
fpt=fopen("sinhvien.dat","wb");
do
{
printf("nhap ma so:");
gets(maso);
if(strlen(maso))
 {

  strcpy(sv.ms,maso);
  printf("ten:");gets(sv.name);
  printf("diem:");scanf("%f",&sv.diem);
  flushall();
  printf("-----------------------------------\n");
  fwrite(&sv,sizeof(struct sinhvien),1,fpt);
 ++i;
 }
}while(strlen(maso));
fclose(fpt);
}

}
///////////////////////////////////////

void themds()
{
struct sinhvien sv;
char maso[5];
fpt=fopen("sinhvien.dat","a+b");
do
{
printf("nhap ma so:");
gets(maso);
if(strlen(maso))
 {

  strcpy(sv.ms,maso);
  printf("ten:");gets(sv.name);
  printf("diem:");scanf("%f",&sv.diem);
  flushall();
  printf("-----------------------------------\n");
  fwrite(&sv,sizeof(struct sinhvien),1,fpt);
 ++i;
 }
}while(strlen(maso));
fclose(fpt);
}
///////////////////////////////////////

void xuatfile()
{
struct sinhvien *ptr;

fpt=fopen("sinhvien.dat","rb");
do
{
ptr=(struct sinhvien*)calloc(1,sizeof(struct sinhvien));
fread(ptr,sizeof(struct sinhvien),1,fpt);
ptr->next=NULL;
if(first==NULL) first=last=ptr;
else
  {
  last->next=ptr;
  last=last->next;
  }
}while(!feof(fpt));
fclose(fpt);
}

////////////////////////////////////////////

void display()
{
printf("            DANH SACH SINH VIEN           \n");
printf("|-----------------------------------------|\n");
printf("| MA SO |      TEN      | DIEM |  KET QUA |\n");
printf("|-----------------------------------------|\n");

}
///////////////////////////////////////////

void xuatds()
{
struct sinhvien *ptr;
int j;
ptr=first;
xuatfile();
display();
ptr=first;
while(ptr!=NULL && strlen(ptr->ms)!=NULL)
{
if(ptr->diem>=5)
{
printf("|%7s|%15s|%6.1f|   PASS   |\n",ptr->ms,ptr->name,ptr->diem);
printf("|-----------------------------------------|\n");
}
else
{
printf("|%7s|%15s|%6.1f|   FAIL   |\n",ptr->ms,ptr->name,ptr->diem);
printf("|-----------------------------------------|\n");
}
ptr=ptr->next;
}

//printf("\n");
xoads();
getch();
}

///////////////////////////////////////////

void xoanode()
{
struct sinhvien *ptr;
char maso[5],chon;
int count=0,j=0;
struct sinhvien *q=NULL;
ptr=first;
xuatfile();
ptr=first;
printf("nhap ma so sv can xoa:");
gets(maso);
if(strlen(maso))
 while(ptr!=NULL)
 if(strcmp(ptr->ms,maso)==0)
  {
  printf("tim thay node can xoa.ban co muon xoa ko?(C/K):\n");
   do
   {
    chon=toupper(getchar());
   }while(chon!='C' && chon!='K');
   flushall();
   if(chon=='C')
   {
    if(q==NULL)
    {
     q=first;
     first=first->next;
    }
    q->next=ptr->next;
    free(ptr);
    count=1;
    --i;
    break;
   }
  }
 else
 {
  q=ptr;
  ptr=ptr->next;}


if(count==1)
{
printf("du lieu sv ma so %s da duoc xoa thanh cong!!!\n",maso);
fpt=fopen("sinhvien.dat","wb");
ptr=first;
while(ptr!=NULL)
{
fwrite(ptr,sizeof(struct sinhvien),1,fpt);
ptr=ptr->next;
}

fclose(fpt);
xuatds();
}
if(count==0)
printf("du lieu sv ma so %s xoa that bai!!!\n",maso);

xoads();
}
//////////////////////////////////////////////

void timkiem()
{
struct sinhvien *ptr;
char maso[5];
int n=0;
ptr=first;
xuatfile();
ptr=first;
printf("nhap ma so hoc sinh can tim:");
gets(maso);
if(strlen(maso))
while(ptr!=NULL)
  if(strcmp(ptr->ms,maso)==0)
  {
     display();
      if(ptr->diem>=5)
      {
       printf("|%7s|%15s|%6.1f|   PASS   |\n",ptr->ms,ptr->name,ptr->diem);
       printf("|-----------------------------------------|\n");
      }
       else
       {
        printf("|%7s|%15s|%6.1f|   FAIL   |\n",ptr->ms,ptr->name,ptr->diem);
        printf("|-----------------------------------------|\n");
       }
      n=1;
      break;
  }
else
ptr=ptr->next;

if(!n)
printf("khong tim thay du lieu hoc sinh can tim!!!\n");
getch();
xoads();
}

void menu()
{
printf("************************\n");
printf("* 1.tao danh sach moi  *\n");
printf("* 2.them danh sach     *\n");
printf("* 3.hien danh sach     *\n");
printf("* 4.tim kiem theo ma so*\n");
printf("* 5.xoa dl 1 sinh vien *\n");
printf("* 0.thoat              *\n");
printf("************************\n");
printf("ban chon? :");
}
main()
{

int chon;
//xuatds();
//xoanode();


do
{
system("cls");
menu();
do
 {
 scanf("%d",&chon);
 flushall();
 }while(chon<0 && chon>5);
switch(chon)
 {
  case 1:nhapdsmoi();break;
  case 2:themds();break;
  case 3:xuatds();break;
  case 4:timkiem();break;
  case 5:xoanode();break;
 }

}while(chon!=0);

xoads();
getch();
}
