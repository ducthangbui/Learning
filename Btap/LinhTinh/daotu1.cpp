#include<stdio.h>
#include<string.h>
void daothutu(char *s)
{
char c[255];
c[0]='\0';
for(int i=strlen(s)-1;i>=0;i--)

if(s[i]==' ')
{
strcat(strcat(c,s+i+1)," ");
s[i]='\0';

}
strcat(c,s);
puts(c);

}
main()
{
	char s[200];
	gets(s);
	daothutu(s);
}
