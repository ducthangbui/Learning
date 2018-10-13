#include <iostream>

using namespace std;

int dem = 0, x[100];//dap an x[i]=j quan hau dat o hang i cot j
bool cot[100];//cot[i] cot thu i
bool xuoi[100],nguoc[100];//duong cheo xuoi, duong cheo nguoc
int n;//so o vuong cua ban co nxn
void Xuat()
{
	cout<<"Loi giai thu "<<++dem<<": ";
	for(int i=1;i<=n;i++)
		cout<<x[i]<<" ";
		cout<<endl;

}

void Try(int i)
{
	for(int j=1;j<=n;j++)
	{
		if( !cot[j] && !xuoi[i-j+n] && !nguoc[i+j-1])
		{
			x[i]=j;
			cot[j]=true;
			xuoi[i-j+n]=true;
			nguoc[i+j-1]=true;
			if( i==n ) Xuat();
			else Try(i+1);
			cot[j]=false;
			xuoi[i-j+n]=false;
			nguoc[i+j-1]=false;
		}
	}
}

int main()
{
	cout<<"Nhap n:";
	cin>>n;
	Try(1);
	return 0;
}
