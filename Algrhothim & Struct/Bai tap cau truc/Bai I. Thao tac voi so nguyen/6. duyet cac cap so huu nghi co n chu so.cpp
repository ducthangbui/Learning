//hai so tu nhien duoc goi la cap so huu ghi neu nhu moi 1 trong so chung
// bang tat ca cac uoc thuc su(ke ca 1) cua so kia.hay tong uoc so nay bang tong uoc so kia ke ca 1
#include "iostream"
#include <math.h>
using namespace std;
int tong_uoc(int k)
{
	int r=k/2,tong=1;
	for(int i=2;i<=r;i++)
		if(k%i==0) tong+=i;
	return tong;
}
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
