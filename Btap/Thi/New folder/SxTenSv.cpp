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
		printf("Nhap vao ten cua sinh vieb thu %d:",i+1);
		gets(a[i].ten);
		printf("Nhap vao ngay,thang,nam sinh cua sinh vien thu %d:",i+1);
		scanf("%d%d%d",&a[i].ngay,&a[i].thang,&a[i].nam);
		printf("Nhap vao dtb cua sinh vien thu %d:",i+1);
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
char *ToWestern(const char*s)
{
	char *ptok,name[30];
	strcpy(name,s);
	char *tmp=(char*)malloc(30);
	tmp[0]='\0';
	ptok=strtok(name," ");
	while(ptok!=NULL)
	{
		strcat(tmp," ");
		strcat(tmp,strrev(ptok));
		ptok=strtok(NULL," ");
	}
	strrev(tmp);
	return tmp;
}
void SxTen(SinhVien a[],int n)
{
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	if(strcmp(ToWestern(a[i].ten),ToWestern(a[j].ten))>0)
	DoiCho(a[i],a[j]);
}
main()
{
	SinhVien a[100];
	int n;
	Nhap(a,n);
	printf("\nDanh sach sinh vien vua nhap la:\n");
	Xuat(a,n);
	printf("\Danh sach sinh vien sap xep theo ten la:\n");
	SxTen(a,n);
	Xuat(a,n);
}
