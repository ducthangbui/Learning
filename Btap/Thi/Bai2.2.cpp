#include<stdio.h>
FILE *f1=fopen("Bai2.2.INP","r");
FILE *f2=fopen("Bai2.2.OUT","w");

void Bai2()
{
	int i,j,t,n,m,a[100][100],b[100][100];
	fscanf(f1,"%d",&t);
	while(t--)
	{
		fscanf(f1,"%d%d",&n,&m);
	
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			fscanf(f1,"%d",&a[i][j]);
			for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			b[i][j]=a[j][i];
			
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				int tich=0;
				for(int k=0;k<m;k++)
				tich=tich+(a[i][k]*b[k][j]);
				fprintf(f2,"%d  ",tich);
			}
				fprintf(f2,"\n");
		}
	}
}

main()
{
	Bai2();
}
