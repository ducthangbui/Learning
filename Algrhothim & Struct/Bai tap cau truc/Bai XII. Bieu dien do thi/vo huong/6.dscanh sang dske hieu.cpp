#include<iostream>
#include<fstream>
#include <stack.h>
#define MAX 100
using namespace std;
ifstream fi;
ofstream fo;

int n,x[MAX][MAX],sc;
stack <int> a[MAX];
void Init()
{
	int i,j;
	fi.open("dscanh.txt");//mo tep de doc
	fi>>n>>sc;
	fo.open("dske.txt");//mo tep de ghi
	fo<<n<<endl;
	
	for(int k=1;k<=sc;k++)
	{
		fi>>i>>j;
		if(i<j) //quy dinh i<j
		{
			a[i].push(j);	//cho vao ngan xep
			a[j].push(i);
		}
		
	}
	
	for(int h=1;h<=n;fo<<endl,h++)//moi 1 h thi xuong dong
		while(!a[h].empty())
		{
			fo<<a[h].top()<<' ';//in canh ngan xep
			a[h].pop();//lay canh ra ngan xep
		}
	fi.close();
	fo.close();
}
main()
{
	Init();
}
