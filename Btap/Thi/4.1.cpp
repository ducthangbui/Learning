#include<stdio.h>
#include<string.h>
void Dem(char*s)
{
	char *ptok,*tmp,*tmp2;
	strcpy(tmp2,s);
	//strcpy(tmp,ptok);
	int a[100],i=0;
	ptok=strtok(s," ");
	a[0]=strlen(ptok);
	while(ptok!=NULL)
	{
		ptok=strtok(NULL," ");
		if(ptok!=NULL)
		{
			a[i+1]=strlen(ptok);
			i++;
		}
	}
	int max=a[0];
	for(int i=1;i<strlen(s);i++)
	{
		if(max<a[i]) max=a[i];
	}
	for(int i=0;i<strlen(s);i++)
	if(max==a[i]) 
	{
		tmp=strtok(tmp2," ");
		a[0]=strlen(tmp);
		while(tmp!=NULL)
	{
		tmp=strtok(NULL," ");
		if(tmp!=NULL)
		{
			a[i+1]=strlen(tmp);
			i++;
			printf("\n%s\t%d",tmp,max);
		}
	}
	}
}
main()
{
	char s[1000];
	gets(s);
	Dem(s);
}
