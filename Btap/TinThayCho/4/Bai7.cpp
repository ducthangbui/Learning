#include<stdio.h>
#include<conio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void ChanLe(int a[],int n)
{
	int demc=0,deml=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0) demc++;
		else deml++;
	}
	printf("Trong day co %d so chan\n",demc);
	printf("Trong day co %d so le",deml);
}
main()
{
	int n,a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	ChanLe(a,n);
	getch();
}
