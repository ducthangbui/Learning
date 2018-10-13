#include "D:\lap trinh\c++\function.cpp"
int x[MAX][MAX],chuaxet[MAX][MAX],n;
void Init()
{
	cout<<"Nhap n= ";cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		chuaxet[i][j]=1;
}
void Print()
{
	for(int i=1;i<=n;cout<<endl,i++)
	for(int j=1;j<=n;j++)
		cout<<setw(3)<<x[i][j]<<' ';
	cout<<"--------------------------\n\n";
}
void Back_MA(int i=1,int j=1,int dem=1)
{
	chuaxet[i][j]=0;
	x[i][j]=dem;
	if(dem==n*n) {Print();getch();}
	else
	{
		if(chuaxet[i+2][j+1]) Back_MA(i+2,j+1,dem+1);
		if(chuaxet[i+2][j-1]) Back_MA(i+2,j-1,dem+1);
		if(chuaxet[i-2][j+1]) Back_MA(i-2,j+1,dem+1);
		if(chuaxet[i-2][j-1]) Back_MA(i-2,j-1,dem+1);
		if(chuaxet[i+1][j+2]) Back_MA(i+1,j+2,dem+1);
		if(chuaxet[i+1][j-2]) Back_MA(i+1,j-2,dem+1);
		if(chuaxet[i-1][j+2]) Back_MA(i-1,j+2,dem+1);
		if(chuaxet[i-1][j-2]) Back_MA(i-1,j-2,dem+1);
	}
	chuaxet[i][j]=1;
}
main()
{
	Init();
	Back_MA();
}