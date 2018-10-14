//006NT2.CPP  Liet ke cac so nguyen to tu m den n
#include <stdio.h>
#include <conio.h>
#include <math.h>
//Ham nt tra ve 1 neu la nguyen to, 0 neu khong phai nguyen to
int nt(int n)
 {int i;
  for(i=2;i<=sqrt(n);i++)
   if(n%i==0) return(0);
  return(1);
 }
void main()
 {clrscr();
  int m,n,i;
  printf("\nNhap m, n = ");scanf("%d%d",&m,&n);
  while(m>=n)
   {printf("\nNhap m, n (m<n) = ");scanf("%d%d",&m,&n);}

  for(i=m;i<=n;i++)
   if(nt(i)) printf("%5d",i);

  gotoxy(2,24);
  printf("Xem xong nhan phim bat ky de ket thuc");
  getch();
 }
/*Bai tap:Nhap mot so m va n sao cho m<n roi in ra cac so nguyen to
 trong khoang [m,n].Neu nhap sai 5 lan thi thong bao va ket thuc
*/