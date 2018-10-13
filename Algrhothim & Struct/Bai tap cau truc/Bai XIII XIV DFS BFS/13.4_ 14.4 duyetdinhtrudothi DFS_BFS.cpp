#include<iostream>
#include<fstream>
using namespace std;
ifstream fi;
int x[100][100],chuaxet[100],n,queue[100],dau=0,cuoi=0;
//Khai bao,khoi tao;
void init()
{
	fi.open("duyetdinhtru.txt");
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
//Ham DFS
void DFS(int v)
{
	chuaxet[v]= 0;
	for(int i=1;i<=n;i++)
	if(chuaxet[i]==1&&x[i][v]==1)
	{
		DFS(i);
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
//Ham BFS
void BFS(int u)
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
			push(i);
			chuaxet[i]=0;
		}
		}
	}
}
//Ham dem thanh phan lien thong
int demtplt()
{
	int dem=0;
	for(int i=1;i<=n;i++)
	{
		if(chuaxet[i]==1)
		{
	 		dem++;	/*chac chan bien dem se tang vi 
			 khoi tao ban dau chuaxet =1,va DFS chua duoc goi ra.	*/	
   		//	DFS(i);
			BFS(i);
		}
	}
	return dem;
}
//Ham duyet dinh tru
void duyetdinhtru()
{
	chuaxettham();
	int f=demtplt(),dem=0;
	for(int i=1;i<=n;i++)
	{
        chuaxet[i]=0;
 		if( f< demtplt())
		{
			cout<<i<<" la dinh tru"<<endl;
			dem++;
		}
	
 		chuaxettham();
	}
	cout<< "Do thi co "<< dem <<"  dinh tru" <<"\n";
}
//Ham main;

main()
{
	init();
	chuaxettham();
	duyetdinhtru();

}