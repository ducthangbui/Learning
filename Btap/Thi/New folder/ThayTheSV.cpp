#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct SinhVien
{
	char ten[30];
	int ngay,thang,nam;
	float dtb;
};
void Nhap(SinhVien a[],int &n)
{
	printf("Nhap vao so sinh vien:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		fflush(stdin);
		printf("Nhap thong tin cua sinh vien thu %d:\n",i+1);
		printf("Nhap vao ten cua sinh vien thu %d:",i+1);
		gets(a[i].ten);
		printf("Nhap vao ngay,thang,nam sinh cua sinh vien thu %d:",i+1);
		scanf("%d%d%d",&a[i].ngay,&a[i].thang,&a[i].nam);
		printf("Nhap vao diem trung binh cua sinh vien thu %d:",i+1);
		scanf("%f",&a[i].dtb);
	}
}
void Xuat(SinhVien a[],int n)
{
	for(int i=0;i<n;i++)
	printf("\n%s\t%d-%d-%d\t%.2f",a[i].ten,a[i].ngay,a[i].thang,a[i].nam,a[i].dtb);
}
void ThayThe(SinhVien a[],int n,SinhVien &x,char *ten)
{
	fflush(stdin);
	printf("Nhap vao thong tin cua sinh vien can thay the:\n");
	printf("Nhap ten cua sinh vien can thay the:");
	gets(x.ten);
	printf("Nhap ngay,thang,nam sinh cua sinh vien can thay the:");
	scanf("%d%d%d",&x.ngay,&x.thang,&x.nam);
	printf("Nhap dtb cua sinh vien can thay the:");
	scanf("%f",&x.dtb);
	fflush(stdin);
	printf("Nhap vao ten sinh vien thay the:");
	gets(ten);
	for(int i=0;i<n;i++)
	if(strcmp(a[i].ten,ten)==0) a[i]=x;
}
main()
{
	SinhVien x,a[100];
	int n;
	char ten[100];
	Nhap(a,n);
	printf("\nDanh sach sinh vien vua nhap la:\n");
	Xuat(a,n);
	printf("\n");
	ThayThe(a,n,x,ten);
	printf("Danh sach sinh vien sau khi thay the la:\n");
	Xuat(a,n);
}
