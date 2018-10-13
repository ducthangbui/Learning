#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *doihe(char *number,int m,int n)
{
	static char ketqua[33];
	char chuso[]="0123456789ABCDGHIJKLMNOPQRSTUVWX";
	int i=0,giatri=0,len;
	len=strlen(number);
	while(i<len)
	{
		giatri=giatri*m+(strchr(chuso,number[i])-chuso);
		i++;
	}
	i=16;
	ketqua[33]=0;
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
	char number[33],*ketqua;
	int n;
	printf("Nhap vao so so can chuyen:");
	scanf("%d",&n);
	fflush(stdin);
	printf("Nhap so can chuyen:");
	gets(number);
	ketqua=doihe(number,10,n);
	printf("\nSo sau khi chuyen tu co so 10 sang co so %d la:%s",n,ketqua);
}
