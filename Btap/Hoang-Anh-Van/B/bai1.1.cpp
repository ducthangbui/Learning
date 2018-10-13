#include<stdio.h>
#include<string.h>
main()
{
	char a[100];
	int dem=0;
	printf("Nhap chuoi:");
	gets(a);
	//strcat(a," ");
	for (int i=0;i<strlen(a);i++)
	if (a[i]==' '&&(a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')) dem++;
	printf("Chuoi vua nhap co %d tu",dem);
}
