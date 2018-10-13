#include<iostream>
#include<fstream>
using namespace std;
ifstream fi;
int x[100][100],chuaxet[100],n,queue[100],dau=0,cuoi=0;
int sc=0, CBT[20][2];
//Khai bao,khoi tao;
void init()
{
	fi.open("timcaybaotrum.txt");
	if(!fi)
	cout<<"   Loi mo tep   ";
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
void Result()
{
	for(int i=1;i<=sc;i++)
	{
		for(int j=1;j<=2;j++) 
		cout<<CBT[i][j]<<"    ";
		cout<<"\n";
	}
}
// Duyet cay bao trum theo chieu sau DFS
void DFS_TREE(int v)
{
     chuaxet[v]=0;
     for(int i=1;i<=n;i++)
     {
             if(x[v][i]==1&&chuaxet[i]==1)
             {
             	sc++;
             	CBT[sc][1]=v; 
				CBT[sc][2]=i;//nap canh (v,i) vao mang CBT hay hieu nap vao cay bao trum
             	DFS_TREE(i);
             }
    }
}
//Khoi tao ham Push
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
//Khoi tao ham POP
int pop()
{
	int x=queue[dau];
	dau++;
	return x;
}
// Duyet cay bao trum theo chieu sau DFS
//Ham BFS
void BFS_TREE(int u)
{
	push(u);
	chuaxet[u]=0;
	while(dau<=cuoi)
	{
		int m=pop();
		for(int i=1;i<=n;i++)
		{
		if(x[m][i]==1&&chuaxet[i]==1)
		{
 			sc++;
 			CBT[sc][1]=m;
			CBT[sc][2]=i;//nap canh (m,i) vao mang CBT hay hieu nap vao cay bao trum
			push(i);
			chuaxet[i]=0;
		}
		}
	}
}

//Ham main;

main()
{
	init();
	chuaxettham();
    // DFS_TREE(1);
     BFS_TREE(1);
     Result();	

}