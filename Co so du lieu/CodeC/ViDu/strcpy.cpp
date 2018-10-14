#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char*ToWestern(const char*s)
{
    char*ptok,name[30];
    strcpy(name,s);
    char*tmp=(char*)malloc(30);
    tmp[0]='\0';
 
    ptok=strtok( name, " " );
    while ( ptok != NULL )
    {
        strcat( tmp, " ");
        strcat( tmp, strrev( ptok ) );
        ptok=strtok( NULL, " " );
    }
    strrev( tmp );
    return tmp;
}
main()
{
	//char s1[]="abc";
	char s2[]="Nguyen Phan Quang Ninh";
	//char s3[25];
	//strtok(s2," ");
	printf("%s\n",ToWestern(s2));
	printf("%s",s2);
}
