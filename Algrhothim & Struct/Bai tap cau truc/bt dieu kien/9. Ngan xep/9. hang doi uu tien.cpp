#include<iostream>
#include<conio.h>>
using namespace std;
typedef struct heap
{
	int info[1000];
	int spt;
	heap()
	{
		info[0]=100000;
		spt=0;
	}
	void Format()
	{
		for(int i=spt;i>=1;i--)
		{
			int r=i;
			while(info[r]>info[r/2])
			{
				int k=info[r];info[r]=info[r/2];info[r/2]=k;
				r/=2;
			}
		}
	}
	void push(int x)
	{
		spt++;
		info[spt]=x;
		Format();
		
	}
	int pop()
	{
		if(spt==0){cout<<"Empty \n";return -1;} 
		int k=info[1];
		int r=info[spt];info[spt]=info[1];info[1]=r;
		spt--;
		Format();
		return k;
	}
	void Print()
	{
		for(int i=spt;i>=1;i--) cout<<info[i]<<' ';
		cout<<endl;
	}
};


main()
{
	heap a;
	for(int i=1;i<=15;i++) {a.push(i);}
	int i=1;
	int j=i<<1;
	while(i<=a.spt)
	{
		for(int k=i;k<j&&k<=a.spt;k++)
			cout<<a.info[k]<<' ';
		i<<=1;
		j<<=1;
		cout<<endl;
	}
}
