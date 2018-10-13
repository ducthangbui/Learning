#include<stdio.h>
void NhapMT(int a[][100],int &n)
{
	printf("Nhap vao so nguyen duong n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		printf("Nhap vao phan tu thu [%d][%d]:",i,j);
		scanf("%d",&a[i][j]);
	}
}
void XuatMT(int a[][100],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
}
void Det(int a[][100],int n)
{
	int det=1,k,i,j;
	float b;
	for(int i=0;i<(n-1);i++)
	{
		if(a[i][i]==0)
		{
			k=i+1;
			while ((k<n)&&(a[k][i]==0))
			k++;
		if(k>(n-1)) 
		{
			det=0;
			break;
		}
		else
		{
			det=-det;
			for(j=i;j<n;j++)
			{
				int tmp=a[i][j];
				a[i][j]=a[k][j];
				a[k][j]=tmp;
			}
		}
		}
		for(k=i+1;k<n;k++)
		{
			b=-a[k][i]/a[i][i];
			for(j=i;j<n;j++)
			a[k][j]=a[k][j]+b*a[i][j];
		}
	}
	for (i=0;i<n;i++)
	det=det*a[i][i];
	printf("Dinh thuc cua ma tran vua nhap la:%d",det);
}
main()
{
	int a[100][100],n;
	NhapMT(a,n);
	printf("Ma tran vua nhap la:\n");
	XuatMT(a,n);
	printf("\n");
	Det(a,n);
}
