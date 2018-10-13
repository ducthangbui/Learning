//lien thong manh tren do thi co huong,phuong phap giai la cu lam nhu voi do thi vo huong,kiem tra lien thong
#include<iostream>
#include<fstream>
using namespace std;
ifstream fi;
int x[100][100],chuaxet[100],n,queue[100],dau=0,cuoi=0;

void init()
{
	fi.open("lienthongmanh.txt");
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
//Kiem tra lien thong
int Test()
{
    for(int j=1;j<=n;j++)
    { 
            if(chuaxet[j]==1) 
			return 0;
    }
    return 1;
}
//Kiem tra lien thong manh chi ap dung cho do thi co huong,duyet DFS ,BFS tat ca cac dinh;
int Kt_lt_manh()
{
    for(int i=1;i<=n;i++)
    {
              
              DFS(i); //duyet tat ca cac dinh
              //BFS(i);
              if(Test()==0) return 0;
              chuaxettham();
     }
     return 1;
}

//==============================
int main()
{
     init();
     chuaxettham();
     if(Kt_lt_manh())
	 {cout<<" Do thi co lien thong manh"<<"\n";}
     else
	 cout<<"Do thi khong lien thong manh"<<"\n";
}
