#include<stdio.h>
#include<string.h>
char *FGETS(char *buf, int bsize, FILE *fp)
{
int i;
int c;
int done = 0;
if (buf == 0 || bsize <= 0 || fp == 0)
	return 0;
for (i = 0; !done && i < bsize - 1; i++) 
{
	c = fgetc(fp);
	if (c == EOF) 
	{
	done = 1;
	i--;
	} else {
	buf[i] = c;
	//if (c == '\n') done = 1;
	}
}
buf[i] = '\0';
if (i == 0)
	return 0;
else
	return buf;
}
void DocFile(char s[])
{
	FILE *f;
	int sotu=0;
	f=fopen("1.4.1.txt","rb");
	//fgets(s,1000,f);
	//fflush(stdin);
	while(!feof(f))
	{
		fgets(s,1000,f);
	
	for(int i=0;i<strlen(s);i++)
	//for(int j=i+1;j<strlen(s);j++)
        if(s[i]!=' '&&(s[i+1]==' '||s[i+1]==NULL)) sotu++;}
    printf("So tu = %d",sotu);
    fclose(f);
}
main()
{
	char s[1000];
	DocFile(s);
}
