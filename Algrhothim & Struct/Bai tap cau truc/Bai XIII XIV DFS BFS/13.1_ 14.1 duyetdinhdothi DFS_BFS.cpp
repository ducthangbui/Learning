#include<iostream>
#include<fstream>
using namespace std;
ifstream fi;
int x[100][100],chuaxet[100],n,queue[100],dau=0,cuoi=0;

void intit()
{
	fi.open("duyetdinhdothi.txt");
	if(!fi)
	cout<<"Loi mo tep";
	fi>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		fi>>x[i][j];
	}
	fi.close();
}
void chuaxettham()
{
	for(int i=1;i<=n;i++)
	chuaxet[i]=1;
}
void DFS(int v)
{
	chuaxet[v]= 0;
	cout<<v<<"   ";
	for(int i=1;i<=n;i++)
	if(chuaxet[i]==1&&x[i][v]==1)
	{
		DFS(i);
	}
	
}
void push(int v)
{
	if(dau==0&&cuoi==0)
	{
		dau++;
		cuoi++;
		queue[cuoi]=v;	
	}
	else{
		cuoi++;
		queue[cuoi]=v;
	}
}
int pop()
{
	int x=queue[dau];
	dau++;
	return x;
}
void BFS(int u)
{
	push(u);
	chuaxet[u]=0;
	while(dau<=cuoi)
	{
		int m=pop();
		cout<< m <<"    ";
		for(int i=1;i<=n;i++)
		{
		if(x[m][i]==1&&chuaxet[i]==1)
		{
			push(i);
			chuaxet[i]=0;
		}
		}
	}
}
main()
{
	intit();
	chuaxettham();
	cout<<"Do thi duoc duyet la: ";
//	DFS(2);
	BFS(2);
	
}
