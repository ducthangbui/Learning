#include<stdio.h>
#include<conio.h>
int TinhTong(int a, int b)
{
	return a+b;
	}
int TinhHieu(int a,int b)
{
 return a-b;
}
int TinhTich(int a,int b)
{return a*b;
}
float TinhThuong(int a,int b)
{ return (float)a/b;
}
main()
{
	int a,b;
	printf("Nhap vao hai so a va b: ");
	scanf("%d%d",&a,&b);
	int Tong, Hieu, Tich;
	float Thuong;
	Tong= TinhTong(a,b);
	Hieu = TinhHieu(a, b);
	Tich = TinhTich(a, b);
	Thuong = TinhThuong(a, b);
	printf("%d+%d=%d",a,b,Tong);
	printf("%d-%d=%d",a,b,Hieu);
	printf("%d*%d=%d",a,b,Tich);
	printf("%d/%d=%f",a,b,Thuong);
}
