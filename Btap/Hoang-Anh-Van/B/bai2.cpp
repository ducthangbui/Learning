#include<stdio.h>
#include<string.h>


main()
{
	int n,inhoa=0,inthuong=0;
	//char a[n];
	//printf("Nhap vao so phan tu:");
	//scanf("%d",&n);
	char a[100];
	printf("Nhap vao chuoi:");
	gets(a);
	for(int i=0;i<strlen(a);i++)
	{
	if(a[i]=='A'||a[i]=='B'||a[i]=='C') inhoa++;
	if (a[i]=='a'||a[i]=='b'||a[i]=='c') inthuong++;
    }
	printf("Co %d A,B,C\n",inhoa);
	printf("Co %d a,b,c",inthuong);
}
