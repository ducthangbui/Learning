#include <iostream>
using namespace std;

int mang[100];
int n;
bool ok=true;
void init()
{
	cout<<"Nhap n:";
	cin>>n;
	for(int i=1;i<=n;i++)
	mang[i]=0;
}
void Xuat()
{
	for(int i=1;i<=n;i++)
	cout<<mang[i];
}

void NextBitString()
{
	int i=n;
	while(i>0 && mang[i] != 0)
	{
		mang[i] = 0;
		i--;
	}
	if(i>0) mang[i] = 1;
		else ok = false;
}

int main()
{
	init();
	while(ok==true)
	{
		Xuat();
		NextBitString();
		cout<<endl;
		//Xuat();
	}

	return 0;
}
