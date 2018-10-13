#include<stdio.h>
#include<string.h>
void Ten(char *s)
{
	char Ten[100],Dem[100];
	int i;
	for(i=strlen(s)-1;i>=0;i--)
	if(s[i]==' ') break;
	strcpy(Ten,s+i+1);
	s[i+1]='\0';
	int l=strlen(s)-strlen(strstr(s," "));
	strcpy(Dem,s+l+1);
	s[l]='\0';
	printf("%s %s%s",Ten,Dem,s);
}
main()
{
	char s[100];
	printf("Nhap vao ten-dem-ho:");
	gets(s);
	Ten(s);
}
