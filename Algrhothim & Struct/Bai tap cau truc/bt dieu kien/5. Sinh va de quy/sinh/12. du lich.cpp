#include "D:\lap trinh\c++\function.cpp"
int mt[100][100],x[100],n,kq[100],mini=10000,OK=1;
void Init()
{
	mo_fDoc("du lich.txt");
		fi>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				fi>>mt[i][j];
			x[i]=i;
			kq[i]=0;
		}
	dong_FDoc();
}

void Update()
{
	int tong=0;
	for(int i=1;i<n;i++)
		tong+=mt[x[i]][x[i+1]];
	tong+=mt[x[n]][x[1]];// quay tro lai thanh pho ban dau
	if(tong<mini)
	{
		mini=tong;
		for(int i=1;i<=n;i++)// sao luu ket qua
			kq[i]=x[i];
	}
}
main()
{
	Init();
	while(OK)
	{
		Update();
		next_per(x,n,OK);
	}
	cout<<"Gia tien nho nhat:"<<mini<<endl;
	cout<<"Cach di:";Xuat(kq,n);
}
