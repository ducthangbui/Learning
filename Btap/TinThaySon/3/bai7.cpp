#include<stdio.h>
#include<math.h>
void Tong(int n)
{
	if(n<0) printf("hay nhap so n duong\n");
	else 
	{
		int m,s=0;
		while(n!=0)
		{
			m=n%10;
			n=n/10;
			s=s+m;
		}
	printf("Tong cac chu so cua so vua nhap la:%d\n",s);
	}
}
void ThuaSoNgto(int n)
{
	if (n<0) printf("Hay nhap vao so duong n");
	else 
	{
		int i=2;
		while (i<=sqrt(n))
		{
			while(n%i==0)
			{
				if(n==i) printf("%d",i);
				else printf("%d*",i);
				n=n/i;
			}
			i++;
		}
		if(n>1) printf("%d",n);
	}
}
main()
{
	int n;
	printf("Nhap:");
	scanf("%d",&n);
	Tong(n);
	ThuaSoNgto(n);
}
