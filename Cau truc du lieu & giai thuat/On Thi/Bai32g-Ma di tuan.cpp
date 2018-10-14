#include <iostream>

using namespace std;

int p[]={-2,-2,-1,-1,1,1,2,2};
int q[]={-1,1,-2,2,-2,2,-1,1};
int dem=0;
int x,y;//vi tri xuat phat tai toa do (X,y)
int n;//kich thuoc ban co
int dapan[50][50];
void KhoiTao()
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	dapan[i][j]=0;
	dapan[x][y]=1;
}
void KetQua()
{
	cout<<endl<<"Cach di thu "<<++dem<<":"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<dapan[i][j]<<" ";
		cout<<endl;
	}
}

 void Try(int x,int y,int k)
 {
 	if(k == n*n) KetQua();
 	else
 	{
 		for(int i=0;i<n;i++)
 		{
 			int x1=x+p[i], y1=y+q[i];
 			if(x1>=0 && x1<n && y1>=0 && y1<n)
 			{
 				if (dapan[x1][y1] == 0)
 				{
 					dapan[x1][y1] = k;
 					Try(x1,y1,k+1);
 					dapan[x1][y1]=0;
 				}
 			}
 		}
 	}
 }
 
 int main()
 {
 	cout<<"Nhap kich thuoc cua ban co:";
 	cin>>n;
 	cout<<"Nhap vi tri xuat phat:";
 	cin>>x>>y;
 	
	 KhoiTao();
 	Try(x,y,2);
 	
 	 	if(dem == 0) cout<<"Khong co cach di nao thoa man yeu cau";
 	else cout<<"Co tat ca "<<dem<<" cach di thoa man yeu cau";
 	
 	//KetQua();
 	
 	return 0;
 }
