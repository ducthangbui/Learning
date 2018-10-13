#include<stdio.h>
#include<string.h>
void Dem1(char a[100])
{
	int dem1=0,dem2=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='A'||a[i]=='B'||a[i]=='C') dem1++;
		if(a[i]=='a'||a[i]=='b'||a[i]=='c') dem2++;
	}
	printf("Co tat ca %d ki tu A,B,C\n",dem1);
	printf("Co tat ca %d ki tu a,b,c\n",dem2);
}
void Dem2(char a[100])
{
	int dem=0;
	for(int i=0;i<strlen(a);i++)
	if(a[i]=='a'||a[i]=='b'||a[i]=='c'||a[i]=='A'||a[i]=='B'||a[i]=='C') dem++;
	printf("\nCo tat ca %d ki tu A,B,C k pbiet hoa hay thuong\n",dem);
}
main()
{
	char a[100];
	printf("Nhap chuoi:");
	gets(a);
	Dem1(a);
	Dem2(a);
}
