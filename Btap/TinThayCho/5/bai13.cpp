#include<stdio.h>
#include<string.h>
void Them(char a[],int vt,char &x)
{
	int n=strlen(a);
	if(vt>=0&&vt<=n)
	{
		for(int i=n;i>vt;i--)
		a[i]=a[i-1];
		a[vt]=x;
		//n++;
	}
}
main()
{
	char a[100],b[100];
	printf("Nhap chuoi thu nhat:");
	gets(a);
	printf("Nhap chuoi thu 2:");
	gets(b);
	int vt;
	printf("Nhap vao vi tri can them:");
	scanf("%d",&vt);
	int m=strlen(b)-1;
	for(int i=m;i>=0;i--)
	Them(a,vt,b[i]);
	printf("Chuoi sai khi them la:");
	puts(a);
}
