//006NT1.CPP  Liet ke cac so nguyen to tu 2 den n
#include <stdio.h>
#include <conio.h>
#include <math.h>
void main()
 {clrscr();
  int n,i,j, a[1000];
  printf("\nNhap n = ");scanf("%d",&n);
  for(i=2;i<=n;i++) a[i]=1;//coi nhu i la nguyen to
  for(i=2;i<=n;i++)
  for(j=2;j<=sqrt(i);j++)
   if(i%j==0) a[i]=0;
  printf("\n");
  for(i=2;i<=n;i++)
   if(a[i]) printf("%5d",i);

  gotoxy(2,24);
  printf("Xem xong nhan phim bat ky de ket thuc");
  getch();
 }
/*Bai tap:Nhap mot so m va n sao cho m<n roi in ra cac so nguyen to
 trong khoang [m,n].
*/