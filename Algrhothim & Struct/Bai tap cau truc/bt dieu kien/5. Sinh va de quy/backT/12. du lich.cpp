#include "D:\lap trinh\c++\function.cpp"
int mt[MAX][MAX],x[MAX],n,kq[MAX],mini=10000,chuaxet[MAX];
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
	for(int i=1;i<=n;i++) chuaxet[i]=1;
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
void BackT_PER(int i=1)
{
	for(int j=1;j<=n;j++)
	{
		if(chuaxet[j]) 
		{
			x[i]=j;
			chuaxet[j]=0;
			if(i==n) Update();
			else BackT_PER(i+1);
			chuaxet[j]=1;
		}
	
	}
}
main()
{
	Init();
	BackT_PER();
	cout<<"Gia tien nho nhat:"<<mini<<endl;
	cout<<"Cach di:";Xuat(kq,n);
}
