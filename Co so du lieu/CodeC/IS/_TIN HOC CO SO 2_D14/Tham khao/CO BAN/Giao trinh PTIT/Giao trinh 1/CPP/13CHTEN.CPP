//13CHTEN.CPP, Loai tru dau cach thua trong ten
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//=====================
void chuanhoa(char *s)
 {char *s1; int n, i,k,j;
  n=strlen(s);
  s1=new char[n+1];
  i=k=0;
  while(s[i]==' ') i++;//Cat dau cach ben trai chuoi
  while(i<n)
    {if(s[i]!=' ') s1[k++]=s[i++];
     else
      {s1[k++]=s[i++];
       while(s[i]==' ') i++;
      }
    }
  k=k-1;
  while(s1[k]==' ') k--;//Cat dau cach ben phai chuoi
  s1[k+1]='\0';
  strcpy(s,s1);
 }
//===============================
void main()
{clrscr();
 char *s1="   Nguyen    Anh   Hung    ";
 puts(s1);
 printf("\n");
 chuanhoa(s1);
 printf("\n%s",s1);
 getch();
}