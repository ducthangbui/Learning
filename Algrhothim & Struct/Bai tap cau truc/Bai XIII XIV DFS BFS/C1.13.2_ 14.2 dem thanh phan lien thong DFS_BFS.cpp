#include<iostream>
#include<fstream>
using namespace std;
ifstream fi;
int x[100][100],chuaxet[100],n,queue[100],dau=0,cuoi=0, k=0;
//K la co chuyen trang thai 
//Khai bao,khoi tao;
void intit()
{
	fi.open("demthanhphanlienthong.txt");
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
	chuaxet[i]=0;
}
//Ham DFS
void DFS(int v)
{
	chuaxet[v]= k;
	for(int i=1;i<=n;i++)
	if(chuaxet[i]==0&&x[i][v]==1)
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
	chuaxet[u]=k;
	while(dau<=cuoi)
	{
		int m=pop();
		for(int i=1;i<=n;i++)
		{
		if(x[m][i]==1&&chuaxet[i]==0)
		{
			push(i);
			chuaxet[i]=k;
		}
		}
	}
}
//Ham dem thanh phan lien thong
int demtplt()
{
	//int dem=0;
	for(int i=1;i<=n;i++)
	{
		if(chuaxet[i]==0)
		{
	 		k++;/*Khoi tao mang chuaxet =0 ,luc này k ++ =1,
			  DFS (i) duyet het tplt 1 ,quay lai for voi chua xet =0  tiep theo
			  k++ =2 DFS(i) duyet het tplt 2, lap lai nhu vay den khi duyet het n*/		
   		//	DFS(i);
			BFS(i);
		}
	}
	return k;
}
//Ham main;
main()
{
	intit();
	chuaxettham();
	int t=demtplt(); 
	cout<<"So thanh phan lien thong: "<<t<<"\n";
	if(t==1)cout<<"Do thi lien thong\n";
	else
	{
		cout<<"Cac thanh phan lien thong: \n";
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=n;j++)
			if(chuaxet[j]==i) cout<<j<<"  ";
			cout<<"\n";
		}
	}
}
