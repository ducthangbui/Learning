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
int PT_Max()
{
	int maxi=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(mt[i][j]>maxi) maxi=mt[i][j];
	return maxi;
}
main()
{
	Init();
	cout<<"phan tu lon nhat la: "<<PT_Max();
	
}