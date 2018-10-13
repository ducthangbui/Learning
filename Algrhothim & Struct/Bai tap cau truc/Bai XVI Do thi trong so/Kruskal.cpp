/*Capacity:
- size : tra ve so luong phan tu cua list. ÐPT O(1).
- empty : tra ve true(1) neu list rong, nguoc lai là false(0). ÐPT
O(1).
Truy c.p ph.n t.:
- front: tra ve giá tri phan tu dau tiên. ÐPT O(1).
- back: tra ve giá tri phan tu cuoi cùng. ÐPT O(1).
Chinh sua:
- push_back : thêm phan tu vào o cuoi list. ÐPT O(1).
- push_front : thêm phan tu vào dau list. ÐPT O(1).
- pop_back : loai bo phan tu o cuoi list. ÐPT O(1).
- pop_front : loai bo phan tu o dau list. ÐPT O(1).
- insert (iterator,x): chèn “x” vào truoc vi trí “iterator” ( x có th.
là phan tu hay iterator cua 1 do.n phan tu…). ÐPT là so phan tu thêm
vào.
- erase : xóa phan tu o vi trí iterator. ÐPT là s. ph.n t. b. xóa ði.
- swap : ð.i 2 list cho nhau (ví d.: first.swap(second);). ÐPT O(1).
- clear: xóa list. ÐPT O(n).*/
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
	bool operator < (canh p)/*dó là dinh nghia toán tu < ví du mình có 1 struct
	 phân so khai báo phanso a,b;
	 if(a>b) cout<<"a>b"; 
	 a,b ko ph?i s? nguyên
	 nên làm sao nó bi?t a>b
	 => mình phai dinh nghia toán tu > cho struc phân so
	sau khi dinh nghia roi thì
	dùng a>b thoai mái*/
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
