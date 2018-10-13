#include<iostream>
#include<fstream>
#include<math.h>
#include<iomanip>
using namespace std;
double x[100][100];//mang ma tran
int m;// so hang
int n;// so cot
void Init()
{
	ifstream fi("gauss.txt");
	fi>>m>>n;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
		fi>>x[i][j];
	
	fi.close();
}
void Doihang(int h1,int h2)
{
	double r;
	for(int i=1;i<=n;i++)
	{
		r=x[h1][i];x[h1][i]=x[h2][i];x[h2][i]=r;
	}
}
/*
void Gauss()// so hang = m, so cot n
{
	for(int i=1;i<m;i++)// xoa tam giac duoi
	{
		double toidai=x[i][i];
		int vt=i;
		for(int j=i+1;j<=m;j++)//tim tru toi dai
			if(fabs(x[j][i])>toidai) 
			{
				toidai=fabs(x[j][i]);
				vt=j;
			}
		if(i!=vt) Doihang(i,vt);
		for(int j=i+1;j<=m;j++)
			for(int k=n;k>=i;k--)
				x[j][k]=x[j][k]-x[i][k]*x[j][i]/x[i][i];
	}	
}
*/
int Gauss_jordan()// so hang = m, so cot n
{
	for(int i=1;i<m;i++)// xoa tam giac duoi
	{
		double toidai=x[i][i];
		int vt=i;
		for(int j=i+1;j<=m;j++)//tim tru toi dai
			if(fabs(x[j][i])>toidai) 
			{
				toidai=fabs(x[j][i]);
				vt=j;
			}
		if(i!=vt) Doihang(i,vt);
		for(int j=i+1;j<=m;j++)
			for(int k=n;k>=i;k--)
				x[j][k]=x[j][k]-x[i][k]*x[j][i]/x[i][i];
	}
	if(x[m][m]==0) {cout<<"Khong giai tiep gauss jordan duoc !\n";return 0;}

	for(int i=m;i>1;i--)// xoa tam giac tren // khong can tim tru toi dai nua
		for(int j=i-1;j>=1;j--)
		{
			for(int k=1;k<=n;k++)
			{
				if(k==i) continue;
				x[j][k]=x[j][k]-x[i][k]*x[j][i]/x[i][i];
			}
			x[j][i]=x[j][i]-x[i][i]*x[j][i]/x[i][i];
		}
	return 1;
}
void print()
{
	for(int i=1;i<=m;cout<<endl,i++)
	for(int j=m+1;j<=n;j++)
		cout<<x[i][j]/x[i][i]<<' ';
}
main()
{
	Init();
	if(Gauss_jordan()) print();
}
