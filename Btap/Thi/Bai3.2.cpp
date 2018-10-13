#include<stdio.h>
#include<string.h>
#include<ctype.h>
FILE *f1=fopen("Bai3.2.INP","r");
FILE *f2=fopen("Bai3.2.OUT","w");
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
	int t;
	char s[100];
	fscanf(f1,"%d",&t);
		printf("%d\n",t);
	while(t!=0)
	{
		fgets(s,100,f1);
		fgets(s,100,f1);
		chuanhoachuoi(s);
		//fprintf(f2,"%s",s);
		fputs(s,f2);
		t--;
		printf("%d\n",t);
	}
	fclose(f2);
}
