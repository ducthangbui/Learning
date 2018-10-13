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
		printf("Nhap thong tin sinh vien thu %d:\n",i+1);
		printf("Ten sinh vien thu %d:",i+1);
		gets(a[i].ten);
		printf("Nhap ngay,thang,nam sinh cua sinh vien thu %d:",i+1);
		scanf("%d%d%d",&a[i].ngay,&a[i].thang,&a[i].nam);
		printf("Nhap diem trung binh cua sinh vien thu %d:",i+1);
		scanf("%f",&a[i].dtb);
	}
}
void Xuat(SinhVien a[],int n)
{
	for(int i=0;i<n;i++)
		printf("\n%s\t%d-%d-%d\t%.2f",a[i].ten,a[i].ngay,a[i].thang,a[i].nam,a[i].dtb);
}
void DoiCho(SinhVien &x,SinhVien &y)
{
	SinhVien tmp=x;
	x=y;
	y=tmp;
}
void SxDiem(SinhVien a[],int n)
{
	for(int i=0;i<n-1;i++)
	for(int j=n-1;j>i;j--)
	if(a[i].dtb>a[j].dtb) DoiCho(a[i],a[j]);
}
main()
{
	SinhVien a[100];
	int n;
	Nhap(a,n);
	printf("Danh sach sinh vien vua nhap la:\n");
	Xuat(a,n);
	printf("\nDanh sach Sinh Vien sau khi sap xep theo dtb la:\n");
	SxDiem(a,n);
	Xuat(a,n);
}
