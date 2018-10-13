#include "d:\lap trinh\c++\function.cpp"

main()
{
	int n;
	cout<<"Nhap n=";cin>>n;
	int r=(n-1)/4;
	for(int i=2;i<=r;i++)
	{
		if(ngto(i)&&ngto(4*i+1))
		cout<<i<<' '<<4*i+1<<endl;
	}
}