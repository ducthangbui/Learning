#include<stdio.h>
int ThuanNghich(int n)
{
	int m=0,tmp=n;
	while (n!=0)
	{
		m=m*10+n%10;
		n=n/10;
	}
	if (m==tmp) return 1;
	else return 0;
}
int Tong(int n)
{
	int m=0;
	while (n!=0)
	{
		m=m+n%10;
		n=n/10;
	}
	if (m%10==0) return m;
	else return 0;
}
main()
{
	int n;
	printf("Nhap so n co 6 chu so:");
	scanf("%d",&n);
	if ((n>=100000) && (n<=999999))
	{
	if (ThuanNghich(n)==1) 
	{
		if (Tong(n)==0) printf("Tong cac chu so cua n khong chia het cho 10");
		else printf("Tong cac chu so cua n:%d",Tong(n));
	}
	else printf("So vua nhap khong phai la so thuan nghich. Hay nhap lai!");
	}
	else printf("Nhap lai n");
}
