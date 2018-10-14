#include "bai36d.h" // class's header file
#include <iostream>

using namespace std;

void Bai36d::Xuat(){
	//int a,b;
	if(UCLN(x,y)==0) cout<<"K co UCLN"<<endl;
	else cout<<"UCLN:"<<UCLN(x,y)<<endl;
	if(BCNN(x,y)==0) cout<<"K co BCNN"<<endl;
	else cout<<"\nBCNN:"<<BCNN(x,y)<<endl;
}

int Bai36d::UCLN(int a,int b)
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

int Bai36d::BCNN(int a,int b){
	if(a==0||b==0) return 0;
	else 
	return ((a*b)/UCLN(a,b));
}


