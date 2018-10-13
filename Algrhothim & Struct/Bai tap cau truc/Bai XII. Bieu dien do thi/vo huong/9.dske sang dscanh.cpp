#include<iostream>
#include<fstream>
#include <stack.h>
#define MAX 100
using namespace std;
ifstream fi;
ofstream fo;
int n,x[MAX][MAX],sc=0;
stack <int> a[MAX];
void Init()
{
	char tmp[10*MAX];
	int tong=0;
	fi.open("dske.txt");
	fo.open("dscanh.txt");
	fi>>n;fi.getline(tmp,1000);//doc ca dong
	for(int i=1;i<=n;i++)
	{
		fi.getline(tmp,1000);
		int k=strlen(tmp);
		for(int j=0;j<k;j++)
			if(tmp[j]==' '||tmp[j]==NULL)
			{
				if(i>tong) sc++;
				a[i].push(tong);
				tong=0;			
			} 
			else tong=tong*10+(tmp[j]-48);
	}
	fo<<n<<' '<<sc<<endl;
	for(int h=1;h<=n;h++)
		while(!a[h].empty())
		{
			if(i<a[h].top()) fo<<h<<' '<<a[h].top()<<endl;
			a[h].pop();
		}
	fi.close();
	fo.close();
}
main()
{
	Init();
}
