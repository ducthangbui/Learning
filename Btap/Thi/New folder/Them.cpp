#include<stdio.h>
#include<stdlib.h>
typedef struct SinhVien
{
	char ten[30];
	int ngay,thang,nam;
	float dtb;
};
void Nhap(SinhVien a[],int &n)
{
	printf("Nhap so sinh vien:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		fflush(stdin);
		printf("Nhap thong tin cua sinh vien thu %d:\n",i+1);
		printf("Nhap ten sinh vien thu %d:",i+1);
		gets(a[i].ten);
		printf("Nhap ngay,thang,nam sinh cua sinh vien thu %d:",i+1);
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
void Them(SinhVien a[],int &n,int &vt,SinhVien &x)
{
	fflush(stdin);
	printf("Nhap thong tin sinh vien can them:\n");
	printf("Nhap ten cua sinh vien can them:");
	gets(x.ten);
	printf("Nhap ngay thang,nam,sinh cua sinh vien can them:");
	scanf("%d%d%d",&x.ngay,&x.thang,&x.nam);
	printf("Nhap diem trung binh cua sinh vien can them:");
	scanf("%f",&x.dtb);
	printf("Nhap vao vi tri can them la:");
	scanf("%d",&vt);
	if(vt>=0&&vt<=n)
	{
		for(int i=n;i>vt;i--)
		a[i]=a[i-1];
		a[vt]=x;
		n++;
	}
}
main()
{
	SinhVien x,a[100];
	int n,vt;
	Nhap(a,n);
	printf("\nDanh sach sinh vien vua nhap la:\n");
	Xuat(a,n);
	printf("\n");
	Them(a,n,vt,x);
	printf("\nDan sach sinh vien sau khi them la:\n");
	Xuat(a,n);
}
