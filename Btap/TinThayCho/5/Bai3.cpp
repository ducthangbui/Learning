#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
int ThuanNghich(char n[])
{
	int j=strlen(n)-1,i=0;
	int dem=0;
	while(i<strlen(n)||j>=0)
	{
			i++; j--;
		if(n[i]==n[j]) dem++;
	
	}
	if(dem==strlen(n)) return 1;
						return 0;
}
main()
{
	char n[200];
	printf("Nhap vao so nguyen can ktra:");
	gets(n);
	if(ThuanNghich(n)==1) printf("So vua nhap la so thuan nghich\n");
	else printf("So vua nhap k phai la so thuan nghich\n");
	printf("\nCac so thuan nghich co 6 chu so la:\n");
	for(int i=100000;i<=999999;i++)
	{
		itoa(i,n,10);
		if(ThuanNghich(n)==1) printf("%d ",i);
	}
	getch();
}
