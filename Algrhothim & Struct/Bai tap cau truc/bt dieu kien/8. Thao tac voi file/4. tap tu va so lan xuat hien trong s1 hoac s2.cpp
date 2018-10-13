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
vector <tu> T;
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
		for(int i=0;i<T.size();i++)
			if(strcmp(T.at(i).word,x.word)==0) 
			{
				k=0;
				T.at(i).n++;
			}
		if(k) T.push_back(x);
	}
	while(f2)
	{
		f2>>x.word;x.n=1;
		if(!f2) break;
		k=1;
		for(int i=0;i<T.size();i++)
			if(strcmp(T.at(i).word,x.word)==0) 
			{
				k=0;
				T.at(i).n++;
			}
		if(k) T.push_back(x);
	}
	
	f1.close();
	f2.close();
}
main()
{
	Xuly();
	while(!T.empty())
	{
		T.back().Print();
		T.pop_back();
	}
	
}