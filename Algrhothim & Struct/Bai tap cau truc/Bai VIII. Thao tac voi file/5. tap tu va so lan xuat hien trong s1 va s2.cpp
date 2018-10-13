#include "D:\lap trinh\c++\function.cpp"

struct tu
{
	char word[100];
	int n;
	void Print()
	{
		cout<<"Tu \""<<word<<"\" xuat hien "<<n<<" lan \n";
	}
};
vector <tu> T1,T2;
void Xuly()
{
	ifstream f1("data1.in"),f2("data2.in");
	tu x;
	int k;
	while(f1)
	{
		f1>>x.word;x.n=1;
		if(!f1) break;
		k=1;
		for(int i=0;i<T1.size();i++)
			if(strcmp(T1.at(i).word,x.word)==0) 
			{
				k=0;
				T1.at(i).n++;
			}
		if(k) T1.push_back(x);
	}
	while(f2)
	{
		f2>>x.word;x.n=1;
		if(!f2) break;
		k=1;
		for(int i=0;i<T2.size();i++)
			if(strcmp(T2.at(i).word,x.word)==0) 
			{
				k=0;
				T2.at(i).n++;
			}
		if(k) T2.push_back(x);
	}
	f1.close();
	f2.close();
	for(int i=0;i<T1.size();i++)
	for(int j=0;j<T2.size();j++)
		if(strcmp(T1[i].word,T2[j].word)==0)
			cout<<T1[i].word<<"\txuat hien\t"<<T1[i].n+T2[j].n<<" lan \n";
}
main()
{
	Xuly();
	
}