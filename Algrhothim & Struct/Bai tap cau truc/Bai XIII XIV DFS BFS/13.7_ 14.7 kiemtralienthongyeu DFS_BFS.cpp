//lien thong yeu tren do thi co huong,phuong phap giai la cu lam nhu voi do thi vo huong,kiem tra lien thong
#include<iostream>
#include<fstream>
using namespace std;
ifstream fi;
int x[100][100],chuaxet[100],n,queue[100],dau=0,cuoi=0;

void init()
{
	fi.open("lienthongyeu.txt");
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
            if(chuaxet[j]==1) //xuat hien 1 dinh chua duoc tham
			return 1;
    }
    return 0;
}
//Kiem tra lien thong yeu chi ap dung cho do thi co huong,duyet DFS ,BFS tat ca cac dinh;
int Kt_lt_yeu()
{
    for(int i=1;i<=n;i++)
    {
              
              DFS(i); //duyet tat ca cac dinh lthong yeu 
			  //là khi goi DFS tai tat ca các dinh cua dò thi, nhung chi con 
			  //tai 1 dinh nào dó mà các dinh không dc tham het. là nó dã là lthoong yeu roi
              //BFS(i);
              if(Test()==1) return 1;
              chuaxettham();
     }
     return 0;
}

//==============================
int main()
{
     init();
     chuaxettham();
     if(Kt_lt_yeu())
	 {cout<<" Do thi co lien thong yeu"<<"\n";}
     else
	 cout<<"Do thi khong lien thong yeu"<<"\n";
}
