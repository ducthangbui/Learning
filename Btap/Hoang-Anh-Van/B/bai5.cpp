#include<stdio.h>
#include<string.h>
main()
{
	char a[100];
	int n,m;
	printf("Nhap chuoi:");
	gets(a);
	printf("Nhap so ki tu n can cat:");
	scanf("%d",&n);
	printf("Nhap vi tri m:");
	scanf("%d",&m);
	if (n>100 || m>100 || n>strlen(a) || m>strlen(a)) 
	printf("m hoac n vua nhap qua gioi han cua chuoi");
	else
	{
	for (int i=m-n-1;i<m;i++)
	printf("%c",a[i]);
    }
}
