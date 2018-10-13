#include<stdio.h>
typedef struct SinhVien
{
	char ten[25];
	int ngay;
	int ma;
	float d1,d2,d3,tong;
}SinhVien;
int Tong(SinhVien a[],int n)
{
	for(int i=0;i<n;i++)
	{
		a[i].tong=(a[i].d1+a[i].d2+a[i].d3)/3;
		a[i].ma++;
	}
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	{
		if(a[i].tong<a[j].tong)
		{
			SinhVien tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
	}
}
/*void Xuat(SinhVien a[],int n)
{
	
	for(int i=0;i<n;i++)
	{
		fprintf(f,"%d %s %d %d %.f",&a[i].ma,a[i].ten,&a[i].ngay,&a[i].tong);
	}
}*/
void File()
{
	FILE *f;
	int n;
	SinhVien a[100];
	f=fopen("1.4.10.txt","rt");
	while(!feof(f))
	{
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++)
		{
			fread(&a[i],sizeof(SinhVien),1,f);
			/*fscanf(f,"%d",&a[i].ma);
			printf("%d",a[i].ma);
			fscanf(f,"%s",a[i].ten);
			printf("%s",a[i].ten);
			fscanf(f,"%d",a[i].ngay);
			printf("%d",a[i].ngay);
			fscanf(f,"%f%f%f",&a[i].d1,&a[i].d2,&a[i].d3);*/
			Tong(a,n);
			//printf("%.f",a[i].tong);
		}
	}
	fclose(f);

}
main()
{
	File();
}
