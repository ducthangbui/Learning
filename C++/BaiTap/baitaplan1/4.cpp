#include<iostream>
using namespace std;
void Nhap(int a[])
{
	for(int i=0;i<5;i++)
	cin>>a[i];
}
int Max(int a[])
{
	int max=a[0];
	for(int i=1;i<5;i++)
	if(max>a[i]) max=a[i];
	return max;
}
int Min(int a[])
{
	int min=a[0];
	for(int i=1;i<5;i++)
	if(min<a[i]) min=a[i];
	return min;
}
main()
{
	int a[6];
	Nhap(a);
	cout<<"Max:"<<Max(a)<<endl;
	cout<<"Min:"<<Min(a)<<endl;
}
