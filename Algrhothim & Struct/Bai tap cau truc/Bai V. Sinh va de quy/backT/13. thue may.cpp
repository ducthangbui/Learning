#include "D:\lap trinh\c++\function.cpp"
struct khach
{
	int dau,cuoi;
	bool giao(khach b)
	{
		if(dau<=b.dau&&cuoi>=b.dau||dau<=b.cuoi&&cuoi>=b.cuoi) return 1;
		if(b.dau<=dau&&b.cuoi>=dau||b.dau<=cuoi&&b.cuoi>=cuoi) return 1;
		return 0;
	}
	void print()
	{
		cout<<"("<<dau<<","<<cuoi<<")";
	}
};
khach K[MAX];
int x[MAX],OK,n,kq[MAX],maxi=0;
void Init()
{
	mo_fDoc("thue may.txt");
	fi>>n;
	for(int i=1;i<=n;i++)
	{
		fi>>K[i].dau>>K[i].cuoi;
		kq[i]=x[i]=0;
	}
	OK=1;
	dong_FDoc();
}
void Update()
{
	int songuoi=0,songay=0,truoc;
	for(int i=1;i<=n;i++)
		if(x[i])
		{
			songuoi++;
			if(songuoi==1) songay+=K[i].cuoi-K[i].dau;
			else
			{
				if(K[i].giao(K[truoc])) return;
				songay+=K[i].cuoi-K[i].dau;
			}
			truoc=i;
		}
	if(songay>maxi)
	{
		maxi=songay;
		for(int i=1;i<=n;i++)
			kq[i]=x[i];
	}
}
void BackT_BIT(int i=1)
{
	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if(i==n) Update();
		else BackT_BIT(i+1);
	}
}
main()
{
	Init();
	BackT_BIT();
	cout<<"Max: "<<maxi<<endl;
	cout<<"Lich muon may: ";
	for(int i=1;i<=n;i++)
	if(kq[i]) K[i].print();
	cout<<endl;
}