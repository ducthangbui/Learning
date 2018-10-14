#include<iostream>
using namespace std;
void Tach(int a)
{
	int tmp[6],i=0;
	while(a!=0)
	{
		tmp[i]=a%10;
		a=a/10;
		i++;
	}
	for(int i=5;i>=0;i--)
	cout<<tmp[i]<<" ";
}
main()
{
	int a;
	cin>>a;
	Tach(a);
}
