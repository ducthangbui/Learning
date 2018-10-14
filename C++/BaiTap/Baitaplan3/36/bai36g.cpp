#include "bai36g.h" // class's header file
#include <iostream>
#include <cmath>
using namespace std;
void Bai36g::TichNgto(){
	cout<<"Nhap n:";
	cin>>n;
	cout<<endl<<"Tich ngto cua "<<n<<" la:";
		int i=2;
	while(i<=sqrt(n))
	{
		while(n%i==0)
		{
			if(n==i) cout<<i;
			else cout<<i<<"*";
			n=n/i;
		}
		i++;
	}
	if(n>1) cout<<n;
}

