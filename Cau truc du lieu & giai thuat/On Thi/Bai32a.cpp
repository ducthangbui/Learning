#include <iostream>

using namespace std;

int n, x[100];

void HienThi()
{
	for(int i=1;i<=n;i++)
	cout<<x[i]<<" ";
	cout<<endl;
}
void Try (int i)
{
	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if(i == n) HienThi();
		else Try(i+1);
	}
}
main()
{
	cout<<"Nhap n";
	cin>>n;
	Try(1);
}
