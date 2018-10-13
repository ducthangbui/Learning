#include<stdio.h>
#include<string.h>
char *doihe(char *number,int m,int n)
{
	static char ketqua[17];
	char chuso[]="0123456789ABCDEF";
	int i=0,giatri=0,len;
	len=strlen(number);
	while(i<len)
	{
		giatri=giatri*m+(strchr(chuso,number[i])-chuso);
		i++;
	}
	i=16;
	ketqua[17]=0;
	do
	{
		ketqua[i]=chuso[giatri%n];
		giatri/=n;
		i--;
	}while(giatri>0);
	return (ketqua+i+1);
}
main()
{
	char number[17],*ketqua;
	gets(number);
	ketqua=doihe(number,10,2);
	puts(ketqua);
}

