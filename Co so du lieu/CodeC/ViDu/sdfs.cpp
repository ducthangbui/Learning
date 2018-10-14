#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
main()
{
   int sokt=0,sodong=1,i,c;
   char tenfile[30],dong[256];
   FILE * f;
   printf("Nhap vao ten file:");
   fflush(stdin);
   gets(tenfile);
   f=fopen(tenfile,"w");
   if(f==NULL)
     printf("Khong tao duoc tep!");
   while(1)
    {
      ++i;
      printf("Nhap vao xau %d (Bam phim Enter de ket thuc)",i);
      gets(dong);
      if(strlen(dong)==0) break;
      if(i>1) fputc(10,f); //Ghi ky tu co ma 10 len file:la ky tu xuong dong
      fputs(dong,f);
    }
    fclose(f);
    f=fopen(tenfile,"r");
   if(f==NULL)
     printf("Khong tao duoc tep!");
   do
      {
        putc(c=fgetc(f),stdout);//Ð?c k? t? t? file và hi?n th? lên màn h?nh
        if(c!='\n'&& c!=EOF)
          sokt++;
        if(c=='\n')
          sodong++;
      }while(c!=EOF);
   printf("\n So dong cua file la:%d",sodong);
   printf("\n So ky tu cua file la:%d",sokt);
   fclose(f);
getch();
}
