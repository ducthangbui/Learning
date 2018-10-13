/*Capacity:
- size : tra ve so luong phan tu cua list. �PT O(1).
- empty : tra ve true(1) neu list rong, nguoc lai l� false(0). �PT
O(1).
Truy c.p ph.n t.:
- front: tra ve gi� tri phan tu dau ti�n. �PT O(1).
- back: tra ve gi� tri phan tu cuoi c�ng. �PT O(1).
Chinh sua:
- push_back : th�m phan tu v�o o cuoi list. �PT O(1).
- push_front : th�m phan tu v�o dau list. �PT O(1).
- pop_back : loai bo phan tu o cuoi list. �PT O(1).
- pop_front : loai bo phan tu o dau list. �PT O(1).
- insert (iterator,x): ch�n �x� v�o truoc vi tr� �iterator� ( x c� th.
l� phan tu hay iterator cua 1 do.n phan tu�). �PT l� so phan tu th�m
v�o.
- erase : x�a phan tu o vi tr� iterator. �PT l� s. ph.n t. b. x�a �i.
- swap : �.i 2 list cho nhau (v� d.: first.swap(second);). �PT O(1).
- clear: x�a list. �PT O(n).*/
#include<iostream>
#include<fstream>
#include<conio.h>
#include<list>
using namespace std;
#define MAX 100
int n,mt[MAX][MAX],chuaxet[MAX];
struct canh
{
	int dau,cuoi,value;
	void xuat()
	{
		cout<<"("<<dau<<','<<cuoi<<") = "<<value<<endl;
	}
	bool operator < (canh p)/*d� l� dinh nghia to�n tu < v� du m�nh c� 1 struct
	 ph�n so khai b�o phanso a,b;
	 if(a>b) cout<<"a>b"; 
	 a,b ko ph?i s? nguy�n
	 n�n l�m sao n� bi?t a>b
	 => m�nh phai dinh nghia to�n tu > cho struc ph�n so
	sau khi dinh nghia roi th�
	d�ng a>b thoai m�i*/
	{
		if(p.value>value) return true;
		return false;
	}
};
list <canh> T,kq;
void nhap()
{
	ifstream fi("mtkc.txt");
	fi>>n;
	int k;
	canh a;
	for(int i=1;i<=n;chuaxet[i]=i,i++)
	for(int j=1;j<=n;j++)
	{
		fi>>k;
		if(j>i&&k) 
		{
			a.dau=i;a.cuoi=j;
			a.value=k;
			T.push_back(a);
		}
	}
	fi.close();
}
void Noi_cay(int a,int b)
{
	int x=chuaxet[a],y=chuaxet[b];
	if(y>x)for(int i=1;i<=n;i++) if(chuaxet[i]==y) chuaxet[i]=x;
	if(y<x)for(int i=1;i<=n;i++) if(chuaxet[i]==x) chuaxet[i]=y;
}
void Kruskal()
{
	T.sort();
	do
	{
		canh a=T.front();T.pop_front();//lay canh nho nhat
		if(chuaxet[a.dau]!=chuaxet[a.cuoi]) 
		{
			Noi_cay(a.dau,a.cuoi);
			kq.push_front(a);
		}
	}while(!T.empty());
}
main()
{
	nhap();
	Kruskal();
	while(!kq.empty())
	{
		cout<<kq.front().dau<<' '<<kq.front().cuoi<<endl;
		kq.pop_front();
	}

}
