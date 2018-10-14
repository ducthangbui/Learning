//12GBAC.CPP, Tim to hop cua cac loai giay bac
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//=================
void main()
 {clrscr();
  int x,y,z,i;
  i=0;
  for(x=0;x<=5750/500;x++)
   for(y=0;y<=5750/200;y++)
    for(z=0;z<=5750/50;z++)
      if(x*500+y*200+z*50==5750)
       printf("\n%4d:  %d  %d  %d",++i,x,y,z);
  getch();
 }
