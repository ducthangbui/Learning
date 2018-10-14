#include<iostream>
#include<math.h>
using namespace std;
void ChinhPhuong(int m,int n)
{
	for(int i=m;i<=n;i++)
	if(sqrt(i)==(int)sqrt(i)) cout<<i<<" ";
}
main()
{
	int n,m;
	cin>>m>>n;
	ChinhPhuong(m,n);
}
