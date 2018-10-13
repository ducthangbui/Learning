#include<stdio.h>
#include<conio.h>
void Nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void TimMin(int a[],int n)
{
	int i,min=a[0];
	for(int i=0;i<n;i++)
	if(min>=a[i]) min=a[i];
	printf("Min=%d\n",min);
	printf("\nVi tri cuc tieu: ");
		for(int i=0;i<n;i++)
				if(min==a[i]) printf("[%d]\t",i);
}
main()
{
	int n,a[100];
	printf("Nhap vao so phan tu:");
	scanf("%d",&n);
	Nhap(a,n);
	TimMin(a,n);
	getch();
	
}
