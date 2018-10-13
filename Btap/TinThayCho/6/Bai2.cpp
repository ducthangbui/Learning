#include<stdio.h>
typedef struct SoPhuc
{
	int thuc;
	int ao;
}sp;
void Nhap(sp a[])
{
	for(int i=0;i<2;i++)
	{
		printf("Nhap vao phan thuc cua so phuc thu %d:",i+1);
		scanf("%d",&a[i].thuc);
		printf("Nhap vao phan ao cua so phuc thu %d:",i+1);
		scanf("%d",&a[i].ao);
	}
}
void Xuat(sp a[])
{
	for(int i=0;i<2;i++)
	{
		printf("So phuc thu %d la:%d+%dj\n",i+1,a[i].thuc,a[i].ao);
	}
}
void TongHieu(sp a[])
{
		printf("Tong:%d+%dj",(a[0].thuc)+(a[1].thuc),(a[0].ao)+(a[0].ao));
		printf("\nHieu:%d+%dj",(a[0].thuc)-(a[1].thuc),(a[0].ao)+(a[1].ao));
}
void Tich(sp a[])
{
	int thuc=a[0].thuc*a[1].thuc+a[0].ao*a[1].thuc;
	int ao=a[0].thuc*a[1].ao+a[0].ao*a[1].ao;
	printf("Tich:%d+%dj",thuc,ao);
}
main()
{
	sp a[3];
	Nhap(a);
	Xuat(a);
	printf("\n============================\n");
	TongHieu(a);
	printf("\n============================\n");
	Tich(a);
}
