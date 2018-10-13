#include<stdio.h>

int Tong(int n)
{
	int s=0,m;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		s=s+m;
	}
	return s;
}
void Chuyen16(int n)
{
	int i=0,a[1000],m;
	while(n!=0)
	{
		a[i]=n%16;
		n=n/16;
		i++;
	}
	for(int j=i-1;j>=0;j--)
	{
	switch(a[j])
	{
		case 10: printf("A");break;
		case 11: printf("B");break;
		case 12: printf("C");break;
		case 13: printf("D");break;
		case 14: printf("E");break;
		case 15: printf("F");break;
		default: printf("%d",a[j]);
	}
	}
}
main()
{
	int n;
	printf("Nhap vao so n:");
	scanf("%d",&n);
	printf("Tong cac chu so cua so %d la:%d\n",n,Tong(n));
	printf("So %d sau khi chuyen sang co so 16 la:",n);
	Chuyen16(n);
}

