#include<stdio.h>
#include<stdlib.h>
typedef struct Phanso
{
	int tu;
	int mau;	
}ps;
void NhapPS(ps a[])
{
	for(int i=0;i<2;i++)
	{
		printf("Nhap vao tu cua phan so thu %d:",i+1);
		scanf("%d",&a[i].tu);
		printf("Nhap vao mau so cua phan so thu %d:",i+1);
		scanf("%d",&a[i].mau);
	}
}
void Xuat(ps &x)
{
	printf("%d/%d",x.tu,x.mau);
}
void XuatPS(ps a[])
{
	for(int i=0;i<2;i++)
	{
		printf("Phan so thu %d la:%d/%d\n",i+1,a[i].tu,a[i].mau);
	}
}

int UCLN(int a,int b)
{
	while(b!=0)
	{
		int tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
int BCNN(int a,int b)
{
	return (a/UCLN(a,b))*b;
}
void RutGon(ps &x)
{
	int ucln=UCLN(x.tu,x.mau);
	int a=(x.tu)/ucln;
	int b=(x.mau)/ucln;
	printf("%d/%d\t",a,b);
}
void QuyDong(ps a[])
{
	int bcnn=BCNN(a[0].mau,a[1].mau);
	int c;
	for(int i=0;i<2;i++)
	{
		c=bcnn/(a[i].mau);
		printf("%d/%d\t",(a[i].tu)*c,(a[i].mau)*c);
	}
}
void TongHieu(ps a[])
{
	int bcnn=BCNN(a[0].mau,a[1].mau);
	int c[3],j=0;
	for(int i=0;i<2;i++)
	{
		c[j]=bcnn/a[i].mau;
		j++;
	}
	int d1=(a[0].tu)*c[0];
	int d2=(a[1].tu)*c[1];
	int tong=d1+d2;
	printf("\nTong cua 2 phan so la:%d/%d\n",tong,bcnn);
	printf("Hieu cua 2 phan so la:%d/%d",d1-d2,bcnn);
}
void TichThuong(ps a[])
{
	ps tich;
	tich.tu=(a[0].tu)*(a[1].tu);
	tich.mau=(a[0].mau)*(a[1].mau);
	ps thuong;
	thuong.tu=(a[0].tu)*(a[1].mau);
	thuong.mau=(a[0].mau)*(a[1].tu);
	printf("\nTich cua 2 phan so la:%d/%d",(a[0].tu)*(a[1].tu),(a[0].mau)*(a[1].mau));
	printf("\nThuong cua 2 phan so la:%d/%d",(a[0].tu)*(a[1].mau),(a[0].mau)*(a[1].tu));
	printf("\nTich cua 2 phan so sau khi rut gon la:");
	RutGon(tich);
	printf("\nThuong cua 2 phan so sau khi rut gon la:");
	RutGon(thuong);
}
main()
{
	ps a[3];
	NhapPS(a);
	XuatPS(a);
	printf("\n=================================");
	printf("\nPhan so sau khi rut gon la:\n");
	for(int i=0;i<2;i++)
	RutGon(a[i]);
	printf("\n=================================");
	printf("\nPhan so sau khi Quy dong la:");
	QuyDong(a);
	printf("\n=================================");
	TongHieu(a);
	printf("\n=================================");
	TichThuong(a);

}
