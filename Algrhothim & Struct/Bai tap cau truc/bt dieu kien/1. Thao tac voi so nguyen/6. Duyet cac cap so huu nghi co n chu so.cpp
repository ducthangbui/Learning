#include "d:\lap trinh\c++\function.cpp"

main()
{
	int n;
	cout<<"Nhap n=";cin>>n;
	for(int i=1;i<n;i++)
	{
		int a=tong_uoc(i);
		if(tong_uoc(a)==i&&a<i) cout<<i<<" "<<a<<endl;
	}

}
