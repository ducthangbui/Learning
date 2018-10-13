//tao 1 mang x[] tu 0==> Z .Dung ngan xep luu lai gia tri khi chia cho co so.
//in gia tri trong ngan xep ra va dua vao trong mang x[gtri ngan xep].
#include <iostream>
#include<stack>
using namespace std;
stack <int> a;
main()
{
	int n,b;//1<b<=36
	char x[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout<<"Nhap n=";cin>>n;
	do
	{
		cout<<"Nhap (1<b<= 36) b=";cin>>b;
	}
	while(b<0||b>36);
	while(n!=0)
	{
		a.push(n%b);
		n/=b;
	}
	while(!a.empty())
	{
		cout<<x[a.top()];
		a.pop();
	}
}
