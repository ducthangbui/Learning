#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sothuannghich(char s[])
{
	int l = strlen(s);
    for (int i = 0; i<=l/2; i++)
    if (s[i]!=s[l-i-1]) return 0;
    return 1;
}
main()
{   int i;
	char s[100];
	printf("Nhap vao so can kiem tra:");
	gets(s);
	if(sothuannghich(s)==0) printf("K phai la so thuan nghich\n");
	else printf("So vua nhap la so thuan nghich\n");
	printf("\nCac so thuan nghich co 6 chu so la:\n");
	for (i=100000; i<=999999;i++)
	{
		itoa(i,s,10);
		if (sothuannghich(s)) printf("%d ",i);
	}
}

