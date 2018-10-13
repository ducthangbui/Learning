#include "D:\lap trinh\c++\function.cpp"
int mt[MAX][MAX],n;
void Init()
{
	cout<<"Nhap n = ";cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cout<<"Nhap phan tu a["<<i<<"]["<<j<<"]: ";cin>>mt[i][j];
	}
}
main()
{
	Init();
}