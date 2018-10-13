/*
	dinh nghia : canh cau la canh khi bo no di thi so thanh phan lien thong tang
	
	thuat toan:
		m=so thanh phan lien thong ban dau
		
		
		(1) - Kiem tra canh k xem co phai canh cau hay ko
	 		chung ta se bo canh k(bang cach cho x[i][j]=x[j][i]=0)
			bx=so thanh phan lien thong sau khi bo
			neu bx=m => do la canh cau
			nguoc lai thi ko phai
		
		Nhu vay, chung ta se duyet qua tat ca cac canh cua do thi
			voi moi canh chung ta lam nhu (1)
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fi;
int x[100][100],chuaxet[100],n,queue[100],dau=0,cuoi=0;
//Khai bao,khoi tao;
void init()
{
	fi.open("duyetcanhcaudothi.txt");
	if(!fi)
	cout<<"   Loi mo tep   ";
	fi>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		fi>>x[i][j];
	}

	fi.close();
}/*
	Nhan thay : moi lam dem so thanh phan lien thong thi cac phan tu mang chuaxet deu = 0
	dan~ den' lan dem sau se bi sai => chung ta phai reset mang chuaxet
*/
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
//Ham duyet canh cau
void duyetcanhcau()
{
	chuaxettham();
	int f= demtplt(),dem1=0;
		/*
		do chung ta dang xet tren do thi vo huong (ma tran doi xung)
		=> chung ta chi thao tac tren tam giac tren cua matran
	*/
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i+1;j<=n;j++)
		{
			if(x[i][j]==1)//ton tai canh i-j
			{
				x[i][j]=x[j][i]=0;	//xoa canh
				if(f<demtplt()) //kiem tra so thanh phan
				{
					dem1++;
					cout<<i<<'-'<<j<<endl;	
				}
				x[i][j]=x[j][i]=1; //khoi phuc canh
				chuaxettham();
				
			}
		}
	}
	cout<<"so canh cau:"<<dem1<<"\n";
}
//Ham main;

main()
{
	init();
	chuaxettham();
	duyetcanhcau();

}