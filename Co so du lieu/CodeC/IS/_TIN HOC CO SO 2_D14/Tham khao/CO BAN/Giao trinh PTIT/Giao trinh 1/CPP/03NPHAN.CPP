//03NPHAN.CPP, Chuyen doi mot so thap phan sang so co co so bat ky
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define nmax 40
char itochar(int n)
 {switch(n)
  {case 0:return('0');
   case 1:return('1');
   case 2:return('2');
   case 3:return('3');
   case 4:return('4');
   case 5:return('5');
   case 6:return('6');
   case 7:return('7');
   case 8:return('8');
   case 9:return('9');
   case 10:return('A');
   case 11:return('B');
   case 12:return('C');
   case 13:return('D');
   case 14:return('E');
   case 15:return('F');
   default:return('\0');
  }
 };
char *daochuoi(char *a)
 {int n = strlen(a);int i,j;char ch;char *b;
  b=new char[n+1];
  strcpy(b,a);
  i=0;j=n-1;
  while(i<j)
   {ch=b[i];b[i]=b[j];b[j]=ch;i++;j--;
   }
  return(b);
 };
void main()
 {clrscr();int n,radix,i;char a[20];
  printf("\nNhap so can chuyen doi: ");scanf("%d",&n);
  printf("\nNhap co so: ");scanf("%d",&radix);
  i=0;
  do
   {a[i++]=itochar(n%radix);
    n=n/radix;
   }
  while(n>0);
  a[i]='\0';
  puts(daochuoi(a));
  getch();
 }
