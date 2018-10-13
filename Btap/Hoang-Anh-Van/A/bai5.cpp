/*Tinh n!*/
#include<stdio.h>
int giaithua(int n)
{
	if (n==0 || n==1) return 1;
	else return n*giaithua(n-1); 
}
main()
{
	int n;
	printf("Nhap vao so n:");
	scanf("%d",&n);
	printf("Ket qua la: %d",giaithua(n));
}
