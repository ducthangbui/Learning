//06DCHUOI.CPP, Dao chuoi ky tu  
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define nmax 40
void daochuoi(char *a)
 {int n = strlen(a);int i,j;char ch;
  i=0;j=n-1;
  while(i<j)
   {ch=a[i];a[i]=a[j];a[j]=ch;i++;j--;
   }
 };
//=================================
void main()
 {clrscr();
  char a[20];char *b;
  strcpy(a,"12345678");
  printf("\nChuoi ban dau la: %s",a);
  daochuoi(a);
  printf("\nChuoi dao lai la: %s",a);
  getch();
 }
