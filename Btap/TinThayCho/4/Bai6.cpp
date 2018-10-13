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
void TB(int a[],int n)
{
	int b,c,j=0,k=0;
	float s[100];
	float s1=0,s2=0;
	int dem1=0;
	float tb;
tt:	printf("Nhap b,c:");
	scanf("%d%d",&b,&c);
	if(b>c) 
	{
	printf("Hay nhap b>c.Hay nhap lai\n");goto tt;}
	for(int i=0;i<n;i++)
	{
		if(a[i]>=b&&a[i]<=c) 
		{
			s[j]=a[i];
			j++;
			dem1++;
		}
	}
	if(dem1!=0)
	{
	for(int ij=0;ij<j;ij++)
	{
	s1=s1+s[ij];
	//	printf("%d\n",s[ij]);
	}
	//printf("dem1:%d\n",dem1);
	//printf("Tong:%f\n",s1+s2);
	tb=((s1+s2)/dem1);
	printf("Trung binh:%f",tb);
	}
	else printf("K co ptu nao cua mang nam trong [b,c]\n");
}
main()
{
	int n,a[100];
	printf("Nhap so phan tu cua mang:");
	scanf("%d",&n);
	Nhap(a,n);
	TB(a,n);
	getch();
}
