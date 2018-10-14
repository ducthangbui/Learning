//ZCOPY.CPP
//Copy file.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <math.h>
#include <ctype.h>
main()
 {clrscr();
  int c;
  char t1[14],t2[14];
  FILE *f1,*f2;
  printf("\n Tep nguon:");gets(t1);
  printf("\n Tep dich: ");gets(t2);
  f1=fopen(t1,"rb");
  if(f1==NULL) {printf("\n Tep %s khong ton tai",t1);getch();exit(1);}
  f2=fopen(t2,"wb");
  //while((c=fgetc(f1))!=EOF) fputc(c,f2);
  while(!feof(f1)) fputc(fgetc(f1),f2);
  fclose(f1);
  fclose(f2);
  getch();
 }