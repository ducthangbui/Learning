//14DEMCHU.CPP, dem chu trong chuoi
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
//===========================
//===================================
int demchu(char *s) //Tra ve so chu trong chuoi
 {char *s1; int n,i,dem;
  n=strlen(s);
  s1=new char[n+1];
  strcpy(s1,s);
  chuanhoa(s1);
  n=strlen(s1);
  dem=0;
  for(i=0;i<n;i++)
   if(s1[i]==' ') dem++;
  return(dem+1);
 }
//===================================
void main()
{clrscr();
 char *s1="   Nguyen    Anh   Hung    ";
 puts(s1);
 printf("\nSo tu trong chuoi tren la: %d",demchu(s1));
 getch();
}