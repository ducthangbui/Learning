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
	mo_fDoc("demdong.txt");
	tu x;
	int k;
	while(fi)
	{
		fi>>x.word;x.n=1;
		if(!fi) break;
		k=1;
		for(int i=0;i<T.size();i++)
		{
			if(strcmp(T.at(i).word,x.word)==0) 
			{
				k=0;
				T.at(i).n++;
			}
		}
		if(k) T.push_back(x);
	}
	
	dong_FDoc();
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