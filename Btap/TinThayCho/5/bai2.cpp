#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
    char s[200];
    int sotu=0;
	//i=-1;
    printf(" Nhap xau : ");
    fflush(stdin);
	gets(s);
    //while(s[++i]!=0)
    for(int i=0;i<strlen(s);i++)
        if(s[i]!=' '&&(s[i+1]==' '||s[i+1]==NULL)) sotu++;
    printf("So tu = %d",sotu);
    getch();
}
