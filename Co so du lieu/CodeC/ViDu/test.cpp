#include<stdio.h>
#include<string.h>
void tong(char a[],char b[])
{   char kq[101];
    int  na = strlen(a),nb = strlen(b),i;
	a = strrev(a);
	b = strrev(b);
	a[na]='0';
	a[na+1] =' ';
	for (int i=0;i<=na-nb;i++)
	b[nb+i]='0';
	b[na+1]=' ';
    int nho = 0;
    for (i=0;i<na+1;i++)
     {  int n = a[i]-'0',m=b[i]-'0';
        if (n+m+nho<=9) { kq[i]= ((a[i]-'0')+(b[i]-'0') + nho) + '0'; nho =0;}
		else  kq[i]= ((a[i]-'0')+(b[i]-'0') + nho)+'0',nho=1;
	 }
	kq[i]=' ';
	printf("\n tong 2 so la : ");
	if (kq[strlen(kq)-1]!='0') printf("%c",kq[strlen(kq)-1]);
	for (i = strlen(kq)-2;i>=0;i--)
	printf("%c",kq[i]);
    printf("\n");
}
main()
{ char a[100],b[100];
  printf("\n nhap 2 so a va b lan luot :  "); scanf("%s%s",&a,&b);
  if (strlen(a)>strlen(b)) tong(a,b);
  else tong(b,a);
}
