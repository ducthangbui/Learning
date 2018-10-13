#include<stdio.h>
#include<math.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
int ktngto(int &n)
{
	int ktra=0;
	if(n<2) return 0;
	for(int j=2;j<=sqrt(n);j++)
	if(n%j==0) ktra++;
	if(ktra==0) return 1;
				return 0;
}
void TBAm(int a[],int n)
{
	int dem=0;
	float s=0;
	for(int i=0;i<n;i++)
	if(a[i]<0)
	{
		s=s+a[i];
		dem++;
	}
	if(dem!=0)
	printf("TB Am=%f\n",s/dem);
	else printf("K co so am nao trong mang\n");
}
void TBDuong(int a[],int n)
{
	int dem=0;
	float s=0;
	for(int i=0;i<n;i++)
	if(a[i]>0)
	{
		s=s+a[i];
		dem++;
	}
	if(dem!=0)
	printf("TB Duong:%f\n",s/dem);
	else("K co so duong nao trong mang\n");
}
main()
{
	int n,a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	TBAm(a,n);
	TBDuong(a,n);
	printf("Cac so ngto la:");
	for(int i=0;i<n;i++)
	if(ktngto(a[i])==1) printf("%d ",a[i]);
}
