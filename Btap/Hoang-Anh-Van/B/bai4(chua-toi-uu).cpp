#include<stdio.h>
#include<string.h>
main()
{
	char a[100],b[100];
	printf("Nhap vao chuoi thu 1:");
	gets(a);
	printf("Nhap vao chuoi thu 2:");
	gets(b);
	int ktra=0;
	for (int i=0;i<strlen(a);i++)
	{
	for (int j=0;j<strlen(b);j++)
	if(a[i]==a[j]&&(a[i]!=' ')&&a[j]!=' ') ktra=ktra+1 ;
	}
    printf("%d",ktra);
	if (ktra==strlen(b)) printf("yes");
	else printf("No");

}
