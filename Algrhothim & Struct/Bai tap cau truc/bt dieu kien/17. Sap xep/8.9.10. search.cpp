#include<iostream>
#include<conio.h>
#include<list>
#include<math.h>
using namespace std;
int x[]={0,32,17,49,89,6,25,53,61},n=8;
void select_sort()
{
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
		if(x[i]>x[j]) 
		{
			int r=x[i];x[i]=x[j];x[j]=r;
		}
}
int Search_sequence(int k)
{
	for(int i=1;i<=n;i++)
	if(x[i]==k) return k;
	return -1;
}

int Search_binary(int k)
{
	select_sort();
	int a=1,b=n,c;
	while(a<b)
	{
		c=(a+b)/2;
		if(x[c]>=k) b=c;
		else if(x[c]<k) a=c+1;
	}
	if(a==b&&x[a]==k) return k;
	return -1;
}
int Search_CS(int k)
{
	list <int> e;
	int m=k,r=0,a,b;
	for(int i=1;i<=n;i++) e.push_back(x[i]);
	while(m)
	{
		r++;//so mu cua 10
		a=(int)pow(10,r);b=(int)pow(10,r-1);
		m/=10;
		int cx=e.size();
		for(int i=1;i<=cx;i++)
			if((e.front()%a)/b==(k%a)/b) 
			{
				e.push_back(e.front());
				e.pop_front();
			}
			else e.pop_front();
	}
	a=(int)pow(10,r+1);b=(int)pow(10,r);
	if(e.size()==1) 
		if((e.front()%a)/b==0) return k;
	return -1;
}
main()
{
//	cout<<Search_sequence(6);
//	cout<<Search_binary(6);
//	cout<<Search_CS(6);
}