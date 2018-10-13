#include "d:\lap trinh\c++\function.cpp"

main()
{
	int n;
	cout<<"Nhap n=";cin>>n;
	int k=int(pow(10,n-1)+9);
	int dau=k-k%10,cuoi=dau*10-1;
	for(int i=dau;i<=cuoi;i++)
		if(thuannghich(i)) cout<<i<<endl;
}
