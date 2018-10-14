#include<iostream>
#include<cmath>
using namespace std;
int Ngto(int n)
{
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) return 0;
				return 1;
}
main()
{
	int n;
	cout<<"Ban can tim so nguyen to co bao nhieu chu so?"<<endl;
	cout<<"Lua chon:";
	cin>>n;
	cout<<endl<<"Cac so ngto co "<<n<<" chu so la:"<<endl;
	for(int i=pow(10,n-1);i<=pow(10,n)-1;i++)
	if(Ngto(i)) cout<<i<<"\t";
}
