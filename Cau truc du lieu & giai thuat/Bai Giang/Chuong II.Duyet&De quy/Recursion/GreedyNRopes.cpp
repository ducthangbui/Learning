/*Cho n day voi chieu dai khac nhau
Ta can phai noi cac day lai voi nhau thanh mot day
Chi phi noi 2 day lai voi nhau duoc tinh bang 
tong do dai 2 day. Nhiem vu cua bai toan la tim cach noi cac day lai voi nhau
thanh mot day sao cho chi phi noi day nho nhat */
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int OPT;//Chi phi noi day nho nhat
int doDaiDay[100];//mang luu do dai cua day
//queue <int> luuDoDaiDay;

int n;


struct cmp{
    bool operator() (int a,int b) {
        return a>b;
    }
};

priority_queue <int,vector<int>,cmp >  luuDoDaiDay;

void Nhap()
{
	int x;
	for(int i=1;i<=n;i++)
	{
		cout<<"Do dai day cua day thu "<<i<<":";
		cin>>x;
		luuDoDaiDay.push(x);
	}
}


int GreedyNRopes()
{
	OPT=0;
	while(luuDoDaiDay.size()>1)
	{
		int first=luuDoDaiDay.top();//lay phan tu dau tien trong hang doi luu do dai day
		luuDoDaiDay.pop();//loai phan tu dau tien trong hang doi luu do dai day
		int second=luuDoDaiDay.top();//lay phan tu ke tiep trong hang doi luu do dai day
		luuDoDaiDay.pop();//loai phan tu ke tiep trong hang doi luu do dai day
		OPT=OPT+first+second;//gia tri nho nhat de noi 2 day
		luuDoDaiDay.push(first+second);//dua lai gia tri first va second vao hang doi
	}
	return OPT;
}

main()
{
	cout<<"Nhap n:";
	cin>>n;
	Nhap();

	cout<<"Gia tri nho nhat de noi day:"<<GreedyNRopes();
}
