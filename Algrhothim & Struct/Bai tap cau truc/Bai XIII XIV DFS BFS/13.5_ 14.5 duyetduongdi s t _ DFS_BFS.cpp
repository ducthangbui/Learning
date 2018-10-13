#include<iostream>
#include<fstream>
using namespace std;
ifstream fi;
int x[100][100],chuaxet[100],n,queue[100],dau=0,cuoi=0,truoc[20],t,s;
//Khai bao,khoi tao;
void init()
{
	fi.open("duyetduongdi.txt");
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
		truoc[i]=v;
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
			truoc[i]=m;
			push(i);
			chuaxet[i]=0;
		}
		}
	}
}
//Ket qua
void Result()
{
	if(truoc[t]==0) //tranh bi co lap;
	{
		cout<<"Khong co duong di tu "<<s<<" den "<<t<<"\n";
		return;
	}
	cout<<"Duong di tu "<<s<<" den "<<t<<" la: \n";
	cout<<t<<" <== ";//Lay nguoc tu t <==s vi khi lay s==>t chi xay ra 1 chieu ????
	while(truoc[t]!=s)//khi truoc[t] co thi lap,khong co thi chay xuong cout s;
	{
		cout<<truoc[t]<<" <== ";
		t=truoc[t];
	}
	cout<<s;
}
//Ham main;

main()
{
	cout<<"Nhap dinh dau: "; cin>>s;
	cout<<"\nNhap dinh cuoi: "; cin>>t;
	init();
	chuaxettham();
    DFS(s);
    //BFS(s);
    Result();

}