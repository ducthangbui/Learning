#include<iostream>
#include<math.h>
using namespace std;
float Pi(float c)
{
	int n=0;
	while (((2*n+1)*c)<1)
	{
		n++;
	}
	float s=0;
	for(int i=0;i<=n;i++)
	s=s+pow(-1,i)*1/(2*i+1);
	return 4*s;	
}
main()
{
	float c,s=0;
	cin>>c;
	cout<<"Pi="<<Pi(c);
}
