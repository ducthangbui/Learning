#include<iostream>
#include<fstream>
using namespace std;
ofstream xuat("kquamatran.dat",ios::out);
void Khoitao(int **&a,int &m,int &n)
{
	ifstream Nhap("matran.dat",ios::in);
	//cout<<"Nhap so hang:";
	Nhap>>m;
	//cout<<"Nhap so cot:";
	Nhap>>n;
	a = new int*[m];
	for(int i = 0; i<m; i++)
   a[i] = new int[n];
}
void Huy(int **a,int m,int n)
{
	for(int i = 0; i<m; i++)
   delete []a[i];
	delete []a;
}
void Nhap(int **a,int m,int n)//m hang, n cot
{
	for(int i = 0; i < m; i++)
   	for(int j = 0; j < n; j++)
      {
			cout<<"Nhap phan tu a["<<i<<"]"<<"["<<j<<"]"<<":";
			cin >> a[i][j];
		}
}
void Xuat(int **a,int m,int n)
{
	
	for(int i=0; i<m ;i++)
	{
		for(int j=0;j<n; j++)
			xuat<<a[i][j]<< "  ";
				xuat<< endl;
	}

}
void Tong(int **a,int **b,int hang1,int cot1, int hang2, int cot2)
{
	if((hang1==hang2) && (cot1==cot2))
	{ 
		int i,j;
		for(i=0; i<hang1; i++)
		{
			for(j=0; j<cot1; j++)
			{
				int tong=0;
				tong+= a[i][j] + b[i][j];
				xuat << tong <<" ";
			}
			xuat << endl;
		}
	}
	else
	{
		xuat<<" Khong co tong 2 ma tran" << endl;
	}
}
void Hieu(int **a,int **b, int hang1, int cot1, int hang2, int cot2)
{
	if((hang1==hang2) && (cot1==cot2))
	{
		int i,j;
		for(i=0; i<hang1; i++)
		{
			for(j=0; j<cot1; j++)
			{
				int hieu;
				hieu= a[i][j] - b[i][j];
				xuat << hieu <<" ";
			}
			xuat << endl;
		}
	}
	else 
	{
		xuat<<"Khong co  hieu 2 ma tran " << endl;
	}
}
void Tich(int **a, int **b, int hang1, int cot1, int hang2, int cot2)
{
	int i,j;
	if(cot1 != hang2){
		xuat << endl << "Khong co tich cua 2 ma tran";
		return;
	}
	for(int i=0; i<hang1; i++)
	{
		
		for(int l=0; l<cot2; l++)
		{
			int tich=0;
			for(int j=0; j<hang2; j++)
				tich += a[i][j]*b[j][l];
				xuat << tich << " ";
		}
		xuat << endl;
	}
}
main()
{
	int hang1,cot1,**a, **b;
	int hang2,cot2;
 	Khoitao(a,hang1,cot1);
	Nhap(a,hang1,cot1);
	xuat<<"Ma tran vua nhap la:" << endl;
	Xuat(a,hang1,cot1);
	Khoitao(b,hang2,cot2);
	Nhap(b,hang2,cot2);
	xuat <<"Ma tran vua nhap la:" << endl;
	Xuat(b,hang2,cot2);
	xuat<< endl << "Tong cua 2 ma tran la:" << endl;
	Tong(a,b,hang1,cot1,hang2,cot2);
	xuat << endl << "Hieu cua 2 ma tran la:" << endl;
	Hieu(a,b,hang1,cot1,hang2,cot2);
	xuat << endl << "Tich cua 2 ma tran la:" << endl;
	Tich(a,b,hang1,cot1,hang2,cot2);
	Huy(b,hang2,cot2);
	Huy(a,hang1,cot1);
}
