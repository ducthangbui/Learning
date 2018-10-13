#include<iostream>
using namespace std;
#define MAX 5
struct queue
{
	int Array[MAX+1];
	int dau,cuoi;
	queue()
	{
		dau=cuoi=MAX;
	}
	void Init()
	{
	     cuoi=dau=MAX;
	}
	int Empty()
	{
	    if(cuoi==dau) return 1;    
	    return 0;
	}
	int Full()
	{
	    if(dau==cuoi +1) return 1;
	    return 0;
	}
	void Push(int x)
	{
	     if(Full()) {cout<<"FULL \n"; return;}
	     cuoi=(cuoi==MAX)?0:cuoi+1;
	     Array[cuoi]=x;
	}
	int Pop()
	{
	     if(Empty()) {cout<<"Empty \n";return -1;}
	     dau=(dau==MAX)?0:dau+1;
	     return Array[dau];
	}
	void Print()
	{
		while(!Empty()) cout<<Pop()<<' ';
		cout<<endl;		
	}
};

main()
{
	queue a;
	a.Push(1);
	a.Print();
}