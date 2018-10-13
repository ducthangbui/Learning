#include<Stdio.h>
#include<string.h>
main()
{
	int dem=0;
	char a[100];
	printf("Nhap vao chuoi:");
	gets(a);
 	for (int i=0;i<strlen(a);i++)
 	if (a[i]=='a'||a[i]=='b'||a[i]=='c'||a[i]=='A'||a[i]=='B'||a[i]=='C')
 	dem++;
 	printf("Co %d ky tu A,B,C k phan biet hoa hay thuong",dem);
}
