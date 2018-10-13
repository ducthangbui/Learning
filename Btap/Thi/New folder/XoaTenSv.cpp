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
		printf("Nhap vao thong tin cua sinh vien thu %d:\n",i+1);
		printf("Nhap ten cua sinh vien thu %d:",i+1);
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
void Xoa(SinhVien a[],int &n,int vt)
{
	if(vt>=0&&vt<n)
	{
		for(int i=vt;i<n-1;i++)
		{
			a[i]=a[i+1];
			n--;
		}
	}
}
void XoaTen(SinhVien a[],int &n,char *s)
{
	fflush(stdin);
	printf("Nhap ten can xoa:");
	gets(s);
	for(int i=0;i<n;i++)
		if(strcmp(a[i].ten,s)==0) Xoa(a,n,i);
}
main()
{
	SinhVien a[100];
	int n;
	char s[100];
	Nhap(a,n);
	printf("Danh sach sinh vien vua nhap la:\n");
	Xuat(a,n);
	printf("\n");
	XoaTen(a,n,s);
	printf("Danh sach sinh vien sau khi xoa la:\n");
	Xuat(a,n);
}
