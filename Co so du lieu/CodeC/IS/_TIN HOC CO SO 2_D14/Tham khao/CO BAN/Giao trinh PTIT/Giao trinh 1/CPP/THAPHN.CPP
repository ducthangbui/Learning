#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<iostream.h>
#include<dos.h>
#define height 20  //chieu cao cua cac dia
#define longo 10    //thiet lap do dai chung cua cac dia +do chenh lech duoc thiet bang cach cong them a[i]
int DELAY,N,tocdo,nhac,kieuduongdi,kiemtra;
void *p;
 unsigned long thoigian=0;
 int   dem=0;
int a[]={1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31};//do chenh lech ve chieu dai cua cac dia
int mau[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};//Mau cua cac dia
int x1=140,x2=320,x3=500,y1,y2,y3;
void taodia(int ,int ,int );
void xoadia(int ,int ,int );
void khoitao();  //xep cac dia o cot A
void screen();   //luu man hinh truoc khi dich chuyen de xem
void batdau();//khoi tao cac gia tri cho so dia,toc do,tao nhac,kieu duong di.Va no duoc khoi tao tu TEXT
void vedongho();//ve dong ho thoi gian
void time(unsigned long i);//viet thoi gian sau mot lan dich chuyen
void khoitaoct();//tao lap do hoa va trang tri man hinh
void chuyendia(int ,int ,int ,int ,int );
void hanoi(int ,int ,int ,int ,int ,int ,int);
void luu_anh();
void in();
void exit();//dung de dung chuong trinh tam thoi de in,hoac de thoat...
void Thoat();//dung de hoi co thoat khoi chuong trinh hay khong..
void continues();// tiep tuc ...
int menu(char *st[]);//hoi dap
//THUC HIEN CAC HAM
void vekhung(int x1,int y1,int x2,int y2)
	{ setfillstyle(SOLID_FILL,MAGENTA);
	 bar(x1,y1,x2,y2);
	 setcolor(YELLOW);
	 rectangle(x1,y1,x2,y2);
	 setcolor(YELLOW);
	 rectangle(x1+2,y1+2,x2-2,y2-2);
	}
void hienthi(char *st,int tt)
	{  int m=strlen(st);
	  if(tt==0){setfillstyle(SOLID_FILL,BLUE);
		    bar(255,255,337,282);
		    setfillstyle(SOLID_FILL,WHITE);
		    bar(250,250,330,275);
		   setcolor(LIGHTMAGENTA);
		   settextstyle(2,0,6);
		   outtextxy(250+((80-m*8)/2),255,st);
		   }
	   if(tt==1){ setfillstyle(SOLID_FILL,BLUE);
		    bar(355,255,437,282);
		   setfillstyle(1,WHITE);
		   bar(350,250,430,275);
		   setcolor(LIGHTMAGENTA);
		   settextstyle(2,0,6);
		   outtextxy(350+((80-m*8)/2),255,st);
		    }
	}
void khonghienthi(char *st,int tt)
	{
	  if(tt==0){setfillstyle(SOLID_FILL,BLUE);
		    bar(255,255,337,282);
		    setfillstyle(SOLID_FILL,BROWN);
		    bar(250,250,330,275);
		   setcolor(LIGHTMAGENTA);
		   settextstyle(2,0,6);
		   int m=strlen(st);
		   outtextxy(250+((80-m*8)/2),255,st);
		   }
	   if(tt==1){setfillstyle(SOLID_FILL,BLUE);
		    bar(355,255,437,282);
		   setfillstyle(1,BROWN);
		   bar(350,250,430,275);
		   setcolor(LIGHTMAGENTA);
		   settextstyle(2,0,6);
		   int m=strlen(st);
		   outtextxy(350+((80-m*8)/2),255,st);
		    }
	}
int menu(char *st[])
	{ int dong=0;
	  hienthi(st[0],0);
	  khonghienthi(st[1],1);
	  char ch;
	  do
		{  ch=getch();
		  if(ch==0) ch=getch();
		  if(ch==27) {dong=1;break;}
		   switch(ch)
			{ case 77: {khonghienthi(st[dong],dong);
				    dong++;if(dong>1) dong=0;
				    hienthi(st[dong],dong);}break;
			  case 75:{khonghienthi(st[dong],dong);
				    dong--;if(dong<0) dong=1;
				    hienthi(st[dong],dong);}break;
			}
		}
	  while(ch!=13);
	  return(dong);
	}
void taodia(int x,int y,int k)
	{ int h=(longo+a[k]*8)/2;
	setfillstyle(SOLID_FILL,mau[k]);
	bar(x-h,y-height+1,x+h,y);
	}
void xoadia(int x,int y,int k)
	{ int h=(longo+a[k]*8)/2;
	setfillstyle(SOLID_FILL,BLUE);
	bar(x-h,y-height+1,x+h,y);
	}
void khoitao()
	{ int i;
	for(i=N;i>0;i--)
		taodia(x1,y1-(N-i)*height,i);
	}
void exit()
	{   char ch;
	    if(kbhit())
		  { if((ch=getch())==0) ch=getch();
			   if(ch==68) in();
		    if(toupper(ch)=='Q') Thoat();
			}
	}
void xoamh(int x1,int y1,int x2,int y2)
	{ setfillstyle(1,BLUE);
	  bar(x1,y1,x2,y2);
	}
void luu_anh(int x1,int y1,int x2,int y2)
	{
	 long nsize;
	 nsize=imagesize(x1-10,y1-10,x2+10,y2+10);
	 p=malloc(nsize);
	 getimage(x1-10,y1-10,x2+10,y2+10,p);
	}
void Thoat()
	{ char *st[]={"Co","Khong"};
	  luu_anh(200,190,470,290);
	  vekhung(200,190,470,290);
	  settextstyle(2,0,5);
	  setcolor(LIGHTCYAN);
	  outtextxy(210,210,"Ban muon thoat khoi chuong trinh?");
	  int n;
	  n=menu(st);
	  if(n==0) {delete[]p;exit(1);}
	  if(n==0) goto nhan;
	  nhan:{
		putimage(190,180,p,COPY_PUT);
		delete[]p;p=NULL;}
	}
void landem(int i)// Dung de ghi gia tri bien dem sau khi chuyen dia-duoc dung voi ham chuyendia
	{
	char s[4];
	itoa(i,s,10);
	setfillstyle(SOLID_FILL,0);
	bar(20,60,100,100);
	settextstyle(1,0,4);
	setcolor(YELLOW);
	outtextxy(30,60,s);
	}
 void time(unsigned long i)   //ghi lai thoi gian chuyen dia -duoc dung voi ham chuyendia
	{ long m=i/620;
	 static long b=0;
	 long a;
	  a=m%60;  b=m/60;
	  char s1[3],s2[3];
	  setcolor(BLACK);
	  itoa(a,s1,10);itoa(b,s2,10);
	  setfillstyle(SOLID_FILL,12);
	 bar(180,90,315,120);
	 settextstyle(2,0,6);
	  if(a<10)
	 { outtextxy(280,95,"0"  );
	  outtextxy(290,95, s1);}
	  else
	  outtextxy(280,95,s1);
	  outtextxy(250,95,":");
	  if(b<10)
	  {outtextxy(210,95,"0");
	  outtextxy(220,95,s2);}
	  else
	  outtextxy(210,95,s2);
	}
 void vedongho()
	{  setcolor(YELLOW);
	  rectangle(175,85,320,125);
	  setcolor(CYAN);
	  rectangle(178,88,317,122);
	}
void chuyendia(int x1,int y1,int x2,int y2,int k)
	{ int i;
	int ymin=getmaxy()-(N+2)*height;
	 int hesonhon=0;//khi con cach mot khoang(hesonhon*height) thi dia se doi huong _
			    // tuc la se khong con di thang,No Se di theo hinh thang
	     exit(); //dung de thoat khoi chuong trinh hoac de in ra may in
	  if(kieuduongdi==0&&N<=10) {hesonhon=2;
			 ymin=getmaxy()-(N+5)*height;
			 if(abs(x1-x2)>300) hesonhon=4;} //Hesonhon =4 tuc la khi dia dich chuyen tu cot A ->C thi heso nhon
							 //se thay doi cho can doi voi khi dia dich chuyen tu cot A->B hoac B->C va nguoc lai
	      dem++;landem(dem);
	       exit();
	      for(i=y1;i>ymin+hesonhon*height;i--)
		     { xoadia(x1,i,k);
		      taodia(x1,i-1,k);
		      delay(DELAY);
		      thoigian+=DELAY;
		      time(thoigian);
		      exit();
		      }
		   if(x1<x2)
			{   int j=0;
			   for(i=ymin+hesonhon*height;i>ymin;i--)
				{  xoadia(x1+j,i,k);
				   taodia(x1+j+1,i-1,k);
				   j++;
				   delay(DELAY);
					thoigian+=DELAY;
					time(thoigian);
					exit();
				}
			   for(i=x1+hesonhon*height;i<x2-hesonhon*height;i++)
				{ xoadia(i,ymin,k);
				taodia(i+1,ymin,k);
				delay(DELAY);
				thoigian+=DELAY;
				time(thoigian);
				exit();
				}
				j=hesonhon*height;
			   for(i=ymin;i<ymin+hesonhon*height;i++)
				{
				  xoadia(x2-j,i,k);
				  taodia(x2-j+1,i+1,k);
				  j--;
				 delay(DELAY);
				thoigian+=DELAY;
				time(thoigian);
				exit();
				}
			 }
		   if(x1>x2)
		    {   int j=0;
			   for(i=ymin+hesonhon*height;i>ymin;i--)
				{  xoadia(x1-j,i,k);
				   taodia(x1-j-1,i-1,k);
				   j++;
				   delay(DELAY);
					thoigian+=DELAY;
					time(thoigian);
					exit();
				}
		       for(i=x1-hesonhon*height;i>x2+hesonhon*height;i--)
			{ xoadia(i,ymin,k);
			  taodia(i-1,ymin,k);
			  delay(DELAY);
			  thoigian+=DELAY;
			  time(thoigian);
			  exit();
			}
			j=hesonhon*height;
			   for(i=ymin;i<ymin+hesonhon*height;i++)
				{
				  xoadia(x2+j,i,k);
				  taodia(x2+j-1,i+1,k);
				  j--;
				 delay(DELAY);
				thoigian+=DELAY;
				time(thoigian);
				exit();
				}
		     }
		   for(i=ymin+hesonhon*height;i<y2;i++)
			{ xoadia(x2,i,k);
			 taodia(x2,i+1,k);
			 delay(DELAY);
			 thoigian+=DELAY;
		       if(thoigian>1000)
			time(thoigian);
			exit();
			}
	      if(nhac>0)
		{ sound(random(1000)+200);
		  delay(50);
		  nosound();
		}
	}
void hanoi(int x1,int y1,int x2,int y2,int x3,int y3,int n)
	{ if(n==1)
		chuyendia(x1,y1,x2,y2,1);
		else    {
			hanoi(x1,y1-height,x3,y3,x2,y2,n-1);
			chuyendia(x1,y1,x2,y2,n);
			hanoi(x3,y3,x2,y2-height,x1,y1,n-1);
			}
	}
void continues()
	{     char *st[]={"Tiep tuc","Thoat"};
		vekhung(200,190,470,290);
		settextstyle(2,0,5);
		setcolor(LIGHTCYAN);
		outtextxy(240,210,"Moi ban tiep tuc?");
		int n;n=menu(st);
		 if(n==1) exit(1);
		 if(n==0)  { kiemtra=1;closegraph();}
	}
void main()
	{
	 start:kiemtra=0;thoigian=0;dem=0;batdau();
	 khoitaoct();
	 khoitao();
	 fflush(stdin);
	 screen();
	 hanoi(x1,y1,x2,y2,x3,y3,N);
	 continues();
	 if(kiemtra==1)   goto start;
	 exit();
	 closegraph();
	}
void screen()
	{  vekhung(200,190,470,260);
	   setcolor(LIGHTGRAY);
	   settextstyle(2,0,5);
	   outtextxy(230,200,"An phim bat ky de bat dau");
	   setfillstyle(1,BLUE);
	   bar(305,230,355,250);
	   setfillstyle(1,LIGHTMAGENTA);
	   bar(300,225,350,245);
	   setcolor(WHITE);
	   settextstyle(2,0,7);
	   outtextxy(315,224,"Ok");
	   char k;
	   if(kbhit())
		{ if(k==68) {khoitao();in();}
		  if(toupper(k)=='Q')  Thoat();

		}
	   getch();
	   xoamh(200,190,470,260);
	   khoitao();
	}
 void batdau()
	{
	     do	{
		textmode(C80);
		textbackground(BLACK);
		window(1,1,80,25);
		clrscr();
		printf("\t\t BAI TOAN THAP HA NOI\n");
		printf("Nhap so dia can chuyen(1..12)N=");scanf("%d",&N);}
		while(N<1||N>12);
		printf("\n");
	    char ch;
       printf(" Ban co muon tao nhac khong(C/K)?");scanf("%s",&ch);
	 if(toupper(ch)=='C') nhac=1;
	 else nhac=0;
	do{
	printf("\n Ban hay vao toc do(1..5):");scanf("%d",&tocdo);
	}while(tocdo<1||tocdo>5);
	DELAY=5/tocdo;
	printf("\n Ban hay chon kieu duong di cua dia(n<=10):\n");
	printf("\t(Neu N>10 thi mac dinh se la 1)\n");
	printf("\t\t1.Di theo hinh nguoc chu U\n");
	printf("\t\t0.Di theo hinh nguoc chu V\n");
	printf("Ban chon so:");scanf("%d",&kieuduongdi);

	}
 void khoitaoct()        //trang tri man hinh trong che do do hoa
	{int mh=DETECT,grmode;
	 initgraph(&mh,&grmode,"\\tc\\bgi");
	 int ymax=getmaxy()-39;
	 setbkcolor(DARKGRAY);
	 char n[1],n1[1];
	 y1=ymax;y2=ymax;y3=ymax;
	 setcolor(YELLOW);
	 rectangle(0,0,getmaxx(),getmaxy());
	 rectangle(2,2,getmaxx()-2,getmaxy()-2);
	 setfillstyle(1,BLUE);
	 bar(28,130,612,getmaxy()-35);
	 rectangle(30,132,610,getmaxy()-37);
	 setcolor(CYAN);
	 rectangle(28,130,612,getmaxy()-35);
	 vedongho(); int t=0;
	 time(t);landem(0);
	 setcolor(YELLOW);
	 settextstyle(1,0,2);
	 outtextxy(200,10,"BAI TOAN THAP HA NOI");
	 settextstyle(2,0,5);
	 setcolor(BLUE);
	 outtextxy(10,40,"LAN DI CHUYEN THU:");
	 outtextxy(10,100,"THOI GIAN DICH CHYEN:");
	 setcolor(CYAN);
	 itoa(N,n,10);
	 setcolor(LIGHTMAGENTA);
	 settextstyle(2,0,6);
	 outtextxy(350,40,"Tong so dia can chuyen la:");
	 setcolor(CYAN);
	 settextstyle(2,0,6);
	 outtextxy(350,100,"An     de In -   de thoat");
	 setcolor(YELLOW);
	 outtextxy(350,100,"   F10         Q         ");
	 outtextxy(610,40,n);
	 setcolor(LIGHTGRAY);
	 settextstyle(0,0,1);
	 outtextxy(350,80,"BAN CHON TOC DO:");
	 itoa(tocdo,n1,10);
	 setcolor(GREEN);
	 settextstyle(2,0,6);
	 outtextxy(500,73,n1);
	 settextstyle(0,0,1);
	 setcolor(LIGHTMAGENTA);
	 outtextxy(120,getmaxy()-30,"COT  ");
	 outtextxy(300,getmaxy()-30,"COT  ");
	 outtextxy(480,getmaxy()-30,"COT  ");
	 setcolor(YELLOW);
	 outtextxy(120,getmaxy()-30,"    A");
	 outtextxy(300,getmaxy()-30,"    B");
	 outtextxy(480,getmaxy()-30,"    C");
	 setcolor(LIGHTMAGENTA);
	 rectangle(3,getmaxy()-22,getmaxx()-3,getmaxy()-3);
	 settextstyle(2,0,5);
	 setcolor(YELLOW);
	 outtextxy(5,getmaxy()-20,"  Tac Gia:Le Huu Dam Lop D2000-CNTT .Hoc Vien Cong Nghe Buu Chinh Vien Thong");
	}
 // HAM IN RA VAN BAN
// TREN CAC MAY IN LQ1070, LQ1170, FX1050;
int taomau( int, int , int  );
void inanh( int lanin ,int xt, int yt , int xd, int yd );
void in();
void da_inxong()
	{  vekhung(200,190,470,260);
	   setcolor(LIGHTGRAY);
	   settextstyle(2,0,5);
	   outtextxy(230,200,"An phim bat ky de tiep tuc");
	   setfillstyle(1,BLUE);
	   bar(305,230,355,250);
	   setfillstyle(1,LIGHTMAGENTA);
	   bar(300,225,350,245);
	   setcolor(WHITE);
	   settextstyle(2,0,7);
	   outtextxy(315,224,"Ok");
	   getch();
	   xoamh(200,190,470,260);
	}

void in()
	{   int a = getmaxx() , b = getmaxy();
	    char *st[]={"In","Thoi In"};
	    luu_anh(200,190,470,290);
	    vekhung(200,190,470,290);
	    settextstyle(0,0,1);
	    setcolor(WHITE);
	    outtextxy(270,200,"In hinh anh");
	    setcolor(YELLOW);
	    line(230,210,440,210);
	    setcolor(LIGHTGRAY);
	    settextstyle(2,0,6);
	    outtextxy(220,210,"Tren cac loai may in:");
	    setcolor(YELLOW);
	    outtextxy(250,225,"(LQ1070,LQ1170,FX1050)");
	    int n;n=menu(st);
	     if(n==0) {putimage(190,180,p,COPY_PUT);delete[]p;p=NULL;
		       inanh(1,0,0,a,b);}
	     if(n==1) goto tiep;
	     tiep:{putimage(190,180,p,COPY_PUT);
		    delete[]p;p=NULL;}

	}
int taomau( int k , int x ,int y )
    {
     int c = 0 , i ;
     for( i = 0 ; i < k ; ++i)
	if( getpixel( x , y +i ) ) c = c | ( 128 >> i ) ;
     return c ;
  }

 void inanh( int dd ,int xt, int yt , int xd, int yd )
  {
    // dd : so lan in lai mot dong ;
    char c , ch1 ;
    int scot, m , mm , k, dong , cot , i , j , n1 , n2 ;
    dong = (yd - yt + 1) / 6 ; mm = (yd - yt + 1) % 6 ;
    cot = xd - xt + 1;
    for( i = 0 ; i <= dong ; ++i)
     {
       if( i < dong ) m = 6;
	 else m = mm;
	   if( m > 0 )
	     {
	      scot = 0;
	      for( j = 0 ; j < cot ; ++j)
	       if( taomau( m , xt + j , yt +i*6)) scot = j + 1;
	       if( scot)
		{
		  n1 = scot % 256 ; n2 = scot / 256;
		   for( k = 0 ; k < dd ; ++k)
		   {
		    fprintf(stdprn,"%c%c%c%c%c%c",13,27,'*',0,n1,n2); // LQ
		     for( j = 0 ; j < scot ; ++j)
		      {
			 // Bat phim bat ky
			 if( kbhit())
			   {
			     if(( ch1 = getch()) == 0) getch();
			     if( ch1 == 27 ) goto ket;
			   }
			 c = taomau( m , xt + j , yt +i*6 );
			 fprintf(stdprn,"%c",c);
		      }
		   }
		}
	      fprintf(stdprn,"%c%c%c",27,'A',m);
	     fprintf(stdprn,"\n");
	     }
     }
    ket : fprintf(stdprn," %c%c",27,'@');
   da_inxong();
  }
