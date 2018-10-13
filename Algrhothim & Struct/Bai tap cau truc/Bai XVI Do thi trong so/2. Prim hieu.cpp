/*
- Input: 
	n dinh
	bieu dien do thi = ma tran trong so
	
- Output:
	cay khung ngan nhat
	
- Thuat toan:
	Buoc 1: tim canh nho nhat dua vao cay T
	Buoc 2: tinh canh nho nhat sao cho T khong co chu trinh khi co them canh do
	Buoc 3: neu cay T du canh thi thoat ko thi quay lai B2
*/
/*Capacity:
- size : tra ve so luong phan tu cua list. ÐPT O(1).
- empty : tra ve true(1) neu list rong, nguoc lai là false(0). ÐPT
O(1).
Truy c.p ph.n t.:
- front: tra ve giá tri phan tu dau tiên. ÐPT O(1).
- back: tra ve giá tri phan tu cuoi cùng. ÐPT O(1).
Ch.nh s.a:
- push_back : thêm phan tu vào o cuoi list. ÐPT O(1).
- push_front : thêm phan tu vào dau list. ÐPT O(1).
- pop_back : loai bo phan tu o cuoi list. ÐPT O(1).
- pop_front : loai bo phan tu o dau list. ÐPT O(1).
- insert (iterator,x): chèn “x” vào truoc vi trí “iterator” ( x có th.
là ph.n t. hay iterator c.a 1 ðo.n ph.n t.…). ÐPT là s. ph.n t. thêm
vào.
- erase : xóa ph.n t. . v. trí iterator. ÐPT là s. ph.n t. b. xóa ði.
- swap : ð.i 2 list cho nhau (ví d.: first.swap(second);). ÐPT O(1).
- clear: xóa list. ÐPT O(n).*/

#include<iostream>
#include<fstream>
#include<list>
#include<conio.h>
using namespace std;
#define MAX 100
int n,mt[MAX][MAX],chuaxet[MAX];
struct canh
{
	int dau,cuoi,value;
	canh(int x,int y,int c)
	{
		dau=x;cuoi=y;value=c;
	}
	void xuat()
	{
		cout<<"("<<dau<<','<<cuoi<<") = "<<value<<endl;
	}
};
list <canh> T;
void nhap()
{
	ifstream fi("mtkc.txt");
	fi>>n;
	for(int i=1;i<=n;chuaxet[i]=1,i++)
	for(int j=1;j<=n;j++)
		fi>>mt[i][j];
	fi.close();
}
void Cay_NN()
{
	int x=1,y=2;//luu vi tri
	int min=mt[x][y];
	for(int i=1;i<n;i++)//tim canh nho nhat
	for(int j=i+1;j<=n;j++)
		if(min>mt[i][j]&&mt[i][j]!=0)
		{
			min=mt[i][j];
			x=i;
			y=j;
		}
	chuaxet[x]=chuaxet[y]=0;
	T.push_back(canh(x,y,mt[x][y]));
	while(int(T.size())<n-1)// bo sung lan luot cac canh vao cay T
	{
		min=1000;
		for(int i=1;i<=n;i++)// for chay qua cac dinh tren cay T
		{
			if(chuaxet[i]==0)
			for(int j=1;j<=n;j++)// for chay qua cac dinh ko thuoc T
			{
				if(chuaxet[j]==1)
				if(mt[i][j]&&mt[i][j]<min)
				{
					min=mt[i][j];
					x=i;
					y=j;
				}
			}
		}
		chuaxet[y]=0;
		T.push_back(canh(x,y,mt[x][y]));//bo sung canh
	}
}
void xuat()
{
	while(!T.empty())
	{
		T.back().xuat();
		T.pop_back();
	}
}
main()
{
	nhap();
	Cay_NN();
	xuat();
}