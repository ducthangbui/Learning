#include<stdio.h>
#include"mylib.h"
#include<stdlib.h>
#include<conio.h>
void menu0();
void menu(int a)
{
	int n;
	system("cls");
	switch(a)
	{case 1:{
		printf("MENU Bai %d\n",a);
		printf("1.In ra ket qua\n");
		printf("0.Quay lai\n");
		tt:	printf("Ban chon:");
		scanf("%d",&n);
	switch(n)
	{
		case 1: {
			int b;
			printf("Nhap vao so Fibo can tim:");
			scanf("%d",&b);
			printf("So Fibo thu %d la:%d\n\n",b,Fibo(n));
			//goto tb;			
				}break;
		case 0: {menu0(); system("cls");}break;
		default : {	
		printf("Nhap lai!!!\n");
		goto tt;
		}
	}
	} break;
	case 2:
		{
		printf("MENU Bai %d\n",a);
		printf("1.In ra ket qua\n");
		printf("0.Quay lai\n");
		tt1:	printf("Ban chon:");
		scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
			for(int i=100000;i<=999999;i++)
			if(ThuanNghich(i)==1) printf(" %d ",i);				
		}break;
		case 0: menu0();break;
		default : 
			{
		printf("Nhap lai!!!\n");
		goto tt1;
			}
			}
		}
	case 3:
		{
		printf("MENU Bai %d\n",a);
		printf("1.In ra ket qua\n");
		printf("0.Quay lai\n");
		tt2:printf("Ban chon:");
		scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
			int n,a[1000];
			printf("Nhap vao so n:");
			scanf("%d",&n);
			Fibo1(a,n);
			printf("Day Fibonaxi la:");
			Xuat(a,n);
			printf("\n\n");			
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("\nNhap lai!!!\n");
			goto tt2;
			}
			}
	}
	case 4:
		{
			printf("MENU Bai %d\n",a);
		printf("1.In ra ket qua\n");
		printf("0.Quay lai\n");
		tt3:printf("Ban chon:");
		scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
			int n;
			printf("Nhap n:");
			scanf("%d",&n);
			printf("Tong cac chu so la:%d\n",TongChuSo(n));
			printf("Tich thua so ngto:");
			TichNgto(n);
			printf("\n\n");			
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("Nhap lai!!!\n");
			goto tt3;
			}
			}
		}
	case 5:
		{
			printf("MENU Bai %d\n",a);
			printf("1.In ra ket qua\n");
			printf("0.Quay lai\n");
			tt4:printf("Ban chon:");
			scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
				int n;
				printf("Nhap vao so n:");
				scanf("%d",&n);
				printf("Tong cac chu so cua so %d la:%d\n",n,TongChuSo(n));
				printf("So %d sau khi chuyen sang co so 16 la:",n);
				Chuyen16(n);
				printf("\n\n");			
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("\nNhap lai!!!\n");
			goto tt4;
			}
		}
		}
	case 6:
		{
			printf("MENU Bai %d\n",a);
			printf("1.In ra ket qua\n");
			printf("0.Quay lai\n");
			tt5:printf("Ban chon:");
			scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
				int n;
				printf("Nhap n>0:");
				scanf("%d",&n);
				uocngto(n);	
				printf("\n\n");		
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("\nNhap lai!!!\n");
			goto tt5;
			}
			}
		}
	case 7:
		{
			printf("MENU Bai %d\n",a);
			printf("1.In ra ket qua\n");
			printf("0.Quay lai\n");
			tt6:printf("Ban chon:");
			scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
				int n,a[100];
				printf("Hay nhap so n:");
				scanf("%d",&n);
				printf("Day Fibonaxi voi %d so dau la:",n);
				Fibo1(a,n);
				Xuat(a,n);
				innguyento(n);
				printf("\n\n");			
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("\nNhap lai!!!\n");
			goto tt6;
			}
			}
		}
	case 8:
		{
			printf("MENU Bai %d\n",a);
			printf("1.In ra ket qua\n");
			printf("0.Quay lai\n");
			tt7:printf("Ban chon:");
			scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
				int i;
				for(i=10000;i<=9999999;i++)
				{
				if(kiemtratang(i)==1 && ThuanNghich(i)==1 && kiemtranguyento(i)==1)
				printf("%d\n",i);
				}
				printf("\n\n");		
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("Nhap lai!!!\n");
			goto tt7;
			}
			}
		}
	case 9:
		{
			printf("MENU Bai %d\n",a);
			printf("1.In ra ket qua\n");
			printf("0.Quay lai\n");
			tt8:printf("Ban chon:");
			scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
				int i;
				for(i=1000000;i<=9999999;i++)
				if(ThuanNghich(i)==1&&kiemtra(i)==1&&kiemtranguyento(i)==1) printf(" %d",i);	
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("Nhap lai!!!\n");
			goto tt8;
			}
			}
		}
		case 10:
		{
			printf("MENU Bai %d\n",a);
			printf("1.In ra ket qua\n");
			printf("0.Quay lai\n");
			tt9:printf("Ban chon:");
			scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
				for(int i=1000000;i<=9999999;i++)
				if(ThuanNghich(i)==1&&baso1(i)==1&&kiemtranguyento(i)) printf(" %d",i);
				printf("\n\n");
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("Nhap lai!!!\n");
			goto tt9;
			}
			}
		}
		case 11:
		{
			printf("MENU Bai %d\n",a);
			printf("1.In ra ket qua\n");
			printf("0.Quay lai\n");
			tt10:printf("Ban chon:");
			scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
			printf("Xin vui long doi trong it phut.....\n");
				for(int i=1000000;i<=999999999;i++)
				if(ThuanNghich(i)==1&&TongChiaHetCho10(i)==1&&kiemtra068(i)==1) printf(" %d",i);
				printf("\n\n");
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("Nhap lai!!!\n");
			goto tt10;
			}
			}
		}
		case 12:
		{
			printf("MENU Bai %d\n",a);
			printf("1.In ra ket qua\n");
			printf("0.Quay lai\n");
			tt11:printf("Ban chon:");
			scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
			printf("Xin vui long doi trong it phut.....\n");
				for(int i=1000000;i<=9999999;i++)
				if(kiemtranguyento(i)==1&&Chuso(i)==1&&Dao(i)==1) printf(" %d",i);
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("Nhap lai!!!\n");
			goto tt11;
			}
			}
		}
		case 13:
		{
			printf("MENU Bai %d\n",a);
			printf("1.In ra ket qua\n");
			printf("0.Quay lai\n");
			tt12:printf("Ban chon:");
			scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
					float x,c,a;
					printf("Nhap x:");
					scanf("%f",&x);
					printf("Nhap c:");
					scanf("%f",&c);
					printf("nhap a:");
					scanf("%f",&a);
					printf("e^%.f=%f\n",x,emu(x,c));
					printf("%.f^%.f=%.5f\n\n",a,x,amu(a,x,c));
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("Nhap lai!!!\n");
			goto tt12;
			}
			}
		}
		case 14:
		{
		tb:	printf("MENU Bai %d\n",a);
			printf("1.In ra ket qua\n");
			printf("0.Quay lai\n");
			tt13:printf("Ban chon:");
			scanf("%d",&n);
		switch(n)
			{
		case 1: 
		{
			printf("Nhap n>0:");
			scanf("%d",&n);	
			Pascal(n);
			printf("\n");
			goto tb;			
		}break;
		case 0: menu0();break;
			default : 
			{
			printf("Nhap lai!!!\n");
			goto tt13;
			}
			}
		}	
		
}
}

void menu0()
{
	int n;
	system("cls");
	printf("********************************\n");
	printf("*******Bui Duc Thang************\n");
	printf("*******Lop:AT02*****************\n");
	printf("*******MaSV:B14DCAT238*********\n\n");
	do
	{
		printf("---------MENU Chinh---------\n");
		printf("1.Bai 1\n");
		printf("2.Bai 2\n");
		printf("3.Bai 3\n");
		printf("4.Bai 4\n");
		printf("5.bai 5\n6.Bai 6\n7.Bai 7\n8.Bai 8\n9.Bai 9\n10.Bai 10\n11.Bai 11\n12.Bai 12\n13.Bai 13\n14.Bai 14\n");
		printf("0.Exit\n");
tt:		printf("Ban chon:");
		scanf("%d",&n);
	} while(n<0&&n>14);
	if(n<0||n>14)
	{
	printf("Hay nhap lai!!!\n");
	goto tt;
	}
	if (n==0) 
	{
	printf("\nNhan phim bat ki de thoat\n");
	exit(1);
	}
	menu(n);		
}
main()
{
	menu0();
}
