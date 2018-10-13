#include<stdio.h>
#include<string.h>
#include<ctype.h>
void xoakhoangtrang(char *s)
{
    char *p;
    while (s[0]==' ')
        strcpy(s,s+1);
    while (s[strlen(s)-1]==' ')
        s[strlen(s)-1]='\0';
    for (int i=0; i<strlen(s); i++)
    {
        p=strstr(s,"  ");
        if (p!=NULL) strcpy(p,p+1);
    }
}
void chuanhoachuoi(char *s)
{
    xoakhoangtrang(s);
    strlwr(s);
    s[0]=toupper(s[0]);
    for (int i=1; i<strlen(s);i++)
        if (s[i-1]==' ') s[i]=toupper(s[i]);
}
main()
{
	char s[100];
	gets(s);
	chuanhoachuoi(s);
	printf("Xau sau khi chuan hoa la:%s",s);
}
