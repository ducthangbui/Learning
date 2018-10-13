#include<stdio.h>
#include<stdlib.h>
#include"BuiDucThang.h"
int a[100],n;
void menu0();
void menunhap()
{
	system("cls");
	printf("********************************\n");
	printf("*******Bui Duc Thang************\n");
	printf("*******Lop:AT02*****************\n");
	printf("*******MaSV:B14DCAT238*********\n\n");
	printf("-------------------------------\n");
	printf("\n\n\t\tXin vui long Nhap Mang dau tien!!!\n\n");
	printf("1.Nhap mang\n");
	printf("0.Thoat\n");
	int b;
tt:	printf("Ban chon:");
	scanf("%d",&b);
	switch(b)
	{
		case 1:{
			Nhap(a,n);
			break;
			   }
		case 0:{
			printf("\nBan da chon thoat!!! Nhan phim bat ki de thoat!!!\n");
			exit(1);
			break;
		}
		default: printf("Nhap sai!!! Hay nhap lai!!!\n"); goto tt;
	}
	menu0();		
}
void menu(int c)
{
	//int a[100],n;
	int d;
	system("cls");
	switch(c)
	{
		case 1:{
	b1:		printf("\nMENU Nhap mang\n");
			printf("1.Nhap mang\n");
			printf("0.Quay lai\n");
			//int b;
		tt:	printf("Ban chon:");
			scanf("%d",&d);
		switch(d)
		{
			case 1: {
			Nhap(a,n); 
			goto b1;break;}
			case 0: {
					menu0(); system("cls");}; break;
			default:{
			printf("Nhap sai!!!\n");
						goto tt;}
		} 					
		}
		case 2:
			{
	b2:			printf("Menu Xuat mang\n");
				printf("1.Xuat Mang\n");
				printf("0.Quay lai\n");
				//int b;
		tt1:	printf("Ban chon:");
				scanf("%d",&d);
			switch(d)
				{
					case 1: {
					Xuat(a,n);
					printf("\n\n"); goto b2;break;}
					case 0:{
						menu0(); system("cls");
					}break;
					default: printf("Nhap sai!!!");
					goto tt1;
				}	
			}
		case 3:
		{
		b3:		printf("MENU Tim kiem mot phan tu trong mang\n");
				printf("1.Tim kiem\n");
				printf("0.Quay lai\n");
				//int b;
		tt2:	printf("Ban chon:");
				scanf("%d",&d);
			switch(d)
			{
				case 1:
					{
						printf("Mang vua nhap la:");
						Xuat(a,n);
						printf("\n");
						Tim(a,n);
						printf("\n\n");
						goto b3;
					} break;
					case 0:{
						menu0(); system("cls");
					} break;
				default: printf("Nhap sai!!!");
				goto tt2;	
			}
		}
		case 4: 
		{
	b4:		printf("MENU Kiem tra tinh chat cua mang\n");
			printf("1.Kiem tra \n");
			printf("0.Quay lai\n");
			//int b;
		tt3:	printf("Ban chon:");
			scanf("%d",&d);
			switch(d)
			{
				case 1:{
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
						if(kiemtratang(a,n)==1&&kiemtragiam(a,n)==1) printf("K tang k giam\n");
						else if(kiemtratang(a,n)==1) printf("Tang\n");
						else	if(kiemtragiam(a,n)==1) printf("Giam\n");
						goto b4;				
				} break;
				case 0: {
					menu0(); system("cls");
					
				}	break;
				default: printf("Nhap sai!!!");
				goto tt3;
			}
		}
		case 5: 
		{
	b5:		printf("MENU Gop mang\n");
			printf("1.Gop mang\n");
			printf("0.Quay lai\n");
			//int b;
	tt4:	printf("Ban chon:");
			scanf("%d",&d);
			switch(d)
			{
				case 1: {
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
					printf("Nhap them 1 mang a[] de chen\n");
					int b[100],nb;
					Nhap(b,nb);
					printf("Mang a[] vua nhap la:");
					Xuat(b,nb);
					printf("\n");
					GopMang(a,n,b,nb);
					printf("\n\n"); goto b5;
					break;
				}
				case 0: {
					menu0(); system("cls");
					break;
				}
				default : printf("Nhap sai!!!");
				goto tt4;
			}
		}
		case 6:
		{
	b6:		printf("MENU Tim Max\n");
			printf("1.Tim Max\n");
			printf("0.Quay lai\n");
			//int b;
	tt5:	printf("Ban chon:");
			scanf("%d",&d);
			switch(d)
			{
				case 1:{
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
					Max(a,n);
					printf("\n\n"); goto b6;
					break;
				}
				case 0:{
					menu0(); system("cls");
					break;
				}
				default :printf("Nhap sai!!!");
				goto tt5;
			}
		}
		case 7:
		{
	b7:		printf("MENU Tim Min\n");
			printf("1.Tim Min\n");
			printf("0.Quay lai\n");
			//int b;
	tt6:	printf("Ban chon\n");
			scanf("%d",&d);
			switch(d)
			{
				case 1:{
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
					Min(a,n);
					printf("\n\n");
					goto b7;
					break;
				}
				case 0:{
					menu0(); system("cls");
					break;
				}
				default: printf("Nhap sai!!!");
				goto tt6;
			}	
		}
		case 8:
		{
	b8:		printf("MENU Sap xep tang dan\n");
			printf("1.Sap xep tang\n");
			printf("0.Quay lai\n");
			//int b;
	tt7:	printf("Ban chon:");
			scanf("%d",&d);
			switch(d)
			{
				case 1:{
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
					printf("Mang sau khi sap xep la:");
					SxTang(a,n);
					printf("\n\n"); goto b8;
					break;
				}
				case 0:{
					menu0(); system("cls");
					break;
				}
				default: printf("Nhap sai!!!");
				goto tt7;
			}
		}
		case 9:
		{
	b9:		printf("MENU Sap xep giam dan\n");
			printf("1.Sap xep giam dan\n");
			printf("0.Quay lai\n");
			//int b;
	tt8:		printf("Ban chon:");
			scanf("%d",&d);
			switch(d)
			{
				case 1:{
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
					printf("Mang sau khi sap xep la:");
					SxGiam(a,n);
					printf("\n\n"); goto b9;
					break;
				}
				case 0:{
					menu0(); system("cls");
					break;
				}
				default: printf("Nhap sai!!!");
				goto tt8;
			}
		}
		case 10:
		{
	b10:		printf("MENU Them 1 phan tu vao mang\n");
			printf("1.Them 1 phan tu vao mang\n");
			printf("0.Quay lai\n");
			//int b;
	tt9:		printf("Ban chon:");
			scanf("%d",&d);
			switch(d)
			{
				case 1:{
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
					int x,vt,c;
					printf("Nhap vao phan tu can them:");
					scanf("%d",&x);
				tb0:	printf("Nhap vao vi tri(chi so cua mang) can them:");
					scanf("%d",&vt);
					if(vt>=0&&vt<n)
					{
					printf("Ban muon them vao ben trai hay ben phai\nHay nhap 1 neu ban muon them ben trai hoac 0 de them ben phai\n");
				tb:	printf("Ban chon:");
					scanf("%d",&c);
					if(c==1) Them(a,n,vt,x), Xuat(a,n+1),printf("\n\n"); 
					else if(c==0) Them(a,n,vt+1,x),Xuat(a,n+1),printf("\n\n");
					else {
						printf("Ban da nhap sai!!! Hay nhap lai!!!\n");
						goto tb;
					}
					goto b10;
					} else {
						printf("Ban da nhap sai vi tri!!! hay nhap lai!!!\n\n"); goto tb0;
					}
					break;
				}
				case 0: {
					menu0(); system("cls");
					break;
				}
				default: printf("Nhap sai!!!");
				goto tt9;
			}
		}
		case 11:
		{
	b11:		printf("MENU Chen mang\n");
			printf("1.Chen mang\n");
			printf("0.Quay lai\n");
			//int b;
	tt10:		printf("Ban chon:");
			scanf("%d",&d);
			switch(d)
			{
				case 1:{
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
					int b[100],m;
					printf("Nhap mang them 1 mang a[] nua de chen\n");
					Nhap(b,m);
					printf("Mang a[] de chen la:");
					Xuat(b,m); printf("\n\n");
					int vt,c;
			tb1:		printf("Nhap vao vi tri(chi so cua mang) can chen:");
					scanf("%d",&vt);
					if(vt<n&&vt>=0)
					{
					printf("Ban muon them vao ben trai hay ben phai\nHay nhap 1 neu ban muon them ben trai hoac 0 de them ben phai\n");
			tn:		printf("Ban chon:");
					scanf("%d",&c);
					if(c==1)
					{
						for(int i=m-1;i>=0;i--)
						Them(a,n+m,vt,b[i]);
						Xuat(a,n+m); printf("\n\n");
					}
					else if(c==0)
					{
							for(int i=m-1;i>=0;i--)
							Them(a,n+m,vt+1,b[i]);
							Xuat(a,n+m); printf("\n\n");
					}
					else {
					printf("Nhap sai!!! Nhap lai!!!\n");
						goto tn;}
						goto b11;
					} else {
						printf("Ban da nhap sai vi tri!!! hay nhap lai!!!\n\n"); goto tb1;
					}
					
					break;
				}
				case 0:{
					menu0(); system("cls");
					break;
				}
				default: printf("Nhap sai!!!\n");
				goto tt10;
			}
		}
		case 12:
		{
	b12:		printf("MENU Xoa mot phan tu trong mang\n");
			printf("1.Xoa phan tu\n");
			printf("0.Quay lai\n");
			//int b;
	tt11:		printf("Ban chon:");
			scanf("%d",&d);
			switch(d)
			{
				case 1: {
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
					int vt;
			tb2:		printf("Nhap vao vi tri(chi so cua mang) can xoa:");
					scanf("%d",&vt);
					if(vt<=n&&vt>=0)
					{
					Xoa(a,vt,n);
					Xuat(a,n);
					printf("\n\n");
					goto b12;
					break;} else {
						printf("Ban da nhap sai vi tri !!! Hay nhap lai\n\n");
						goto tb2;
					}
				}
				case 0:{
					menu0(); system("cls");
					break;
				}
				default: printf("Nhap sai!!!\n");
				goto tt11;
			}	
		}
		case 13:
		{
	b13:		printf("MENU Tach Mang\n");
			printf("1.Tach Mang\n");
			printf("0.Quay lai\n");
			//int b;
	tt12:		printf("Ban chon:");
			scanf("%d",&d);
			switch(d)
			{
				case 1:{
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
					int b[100],c[100],vt;
			tb3:		printf("Nhap vao vi tri(chi so cua mang) tach:");
					scanf("%d",&vt);
					if(vt<n&&vt>=0)
					{
					TachMang(a,n,vt);
					printf("\n\n"); goto b13;}
					else {
						printf("Ban da nhap sai!!! Hay nhap lai!!!\n\n"); goto tb3;
					}
					break;
						}
				case 0:{
					menu0(); system("cls");
					break;
				}
				default: printf("Nhap sai!!!");
				goto tt12;		
			}	
		}
		case 14:
		{
	b14:		printf("MENU Sua mot phan tu trong mang\n");
			printf("1.Sua\n");
			printf("0.Quay lai\n");
	tt13:		printf("Ban chon:");
			scanf("%d",&d);
			switch(d)
			{
				case 1:{
					int vt,x;
					printf("Mang vua nhap la:");
					Xuat(a,n);
					printf("\n");
					Sua(a,n,vt,x);
					printf("\n\n");
					goto b14;
					break;
				}
				case 0:{
					menu0();	system("cls");
					break;
				}
				default: printf("Nhap sai!!!");
				goto tt13;
			}
		}	
	} 
}
void menu0()
{
	int c;
	system("cls");
	do
	{
	printf("********************************\n");
	printf("*******Bui Duc Thang************\n");
	printf("*******Lop:AT02*****************\n");
	printf("*******MaSV:B14DCAT238*********\n\n");
	printf("---------MENU Chinh---------\n");
	printf("1.Nhap lai Mang\n");
	printf("2.Xuat Mang\n");
	printf("3.Tim mot phan tu trong mang\n");
	printf("4.Kiem tra tinh chat cua mang\n");
	printf("5.Gop Mang\n");
	printf("6.Tim phan tu Max trong mang\n");
	printf("7.Tim phan tu Min trong mang\n");
	printf("8.Sap xep tang dan\n");
	printf("9.Sap xep giam dan\n");
	printf("10.Them mot phan tu vao mang\n");
	printf("11.Chen Mang\n");
	printf("12.Xoa mot phan tu trong mang\n");
	printf("13.Tach Mang\n");
	printf("14.Sua mot phan tu trong mang\n");
	printf("15.Thoat\n");
tt:	printf("Ban chon:");
	scanf("%d",&c);}
	while(c<1&&c>15);
	if(c<1||c>15) {
		printf("Nhap sai!!! Nhap lai!!!\n");
		goto tt;
	}
	if(c==15) 
	{
		printf("\nNhan phim bat ki de thoat\n");
		exit(1);
	}
	menu(c);		
}
main()
{
	menunhap();
}

