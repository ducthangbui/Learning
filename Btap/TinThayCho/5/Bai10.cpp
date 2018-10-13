#include<stdio.h>
#include<string.h> 
void Dem(char a[])
{
	int dem1=0,dem2=0,dem3=0,dem4=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='a'||a[i]=='A'||a[i]=='e'||a[i]=='E'||a[i]=='o'||a[i]=='O'||a[i]=='u'||a[i]=='U'||a[i]=='i'||a[i]=='I') dem1++;
		if(a[i]>='0'&&a[i]<='9') dem2++;
		if(a[i]<=47||(a[i]>=58&&a[i]<=64)||(a[i]>=91&&a[i]<=96)||a[i]>=123) dem3++;
		if((a[i]>'a'&&a[i]<='z'&&a[i]!='a'&&a[i]!='e'&&a[i]!='o'&&a[i]!='u'&&a[i]!='i')||(a[i]>='A'&&a[i]<='Z'&&a[i]!='A'&&a[i]!='E'&&a[i]!='O'&&a[i]!='I'&&a[i]!='U'))
		dem4++;
	}
	printf("\nCo tat ca %d nguyen am\nCo tat ca %d phu am\nCo tat ca %d ki tu so\nCo tat ca %d cac ki tu khac\n",dem1,dem4,dem2,dem3);
}
main()
{
	char a[100];
	printf("Nhap chuoi:");
	gets(a);
	Dem(a);
}
