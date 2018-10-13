#include<stdio.h>
#include<string.h>
void DaoTu(char *s)
{
	char c[100];
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
	char s[100];
	printf("Nhap chuoi:");
	gets(s);
	DaoTu(s);
}
