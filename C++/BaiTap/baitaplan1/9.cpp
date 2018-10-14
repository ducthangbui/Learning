#include<iostream>
using namespace std;
int UCLN(int a,int b)
{
	if(a==0&&b==0) return 0;
	else
	{
	while(b!=0)
	{
		int tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
	}
}
int BCNN(int a,int b)
{
	if(a==0||b==0) return 0;
	else 
	return ((a*b)/UCLN(a,b));
}
main()
{
	int a,b;
	cin>>a>>b;
	if(UCLN(a,b)==0) cout<<"K co UCLN"<<endl;
	else cout<<"UCLN:"<<UCLN(a,b)<<endl;
	if(BCNN(a,b)==0) cout<<"K co BCNN"<<endl;
	else cout<<"\nBCNN:"<<BCNN(a,b)<<endl;
}
