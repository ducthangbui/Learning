bool test_chanle(char c)
{
	char b[100];
	itoa(int(c),b,2);
	int dem=0;
	for(int i=0;i<strlen(b);i++)
		if(b[i]=='1') dem++;
	return dem%2;
}
unsigned char chanhoa(unsigned char a)
{
	a=a<<1;
	if(test_chanle(a)==1) a+=1;
	
	return a;
}
unsigned char giaimachan(unsigned char a)
{
	return (a>>1);
}
int Tontai_kitu(char a[],char c)// kiem tra xem ki tu c co trong a khong
{
	int n=strlen(a);
	for(int i=0;i<n;i++)
		if(a[i]==c) return 1;
	return 0;
}
struct stringX
{
	string str[1000];
	int count;
	void nhap()
	{
		count=0;
		cout<<"Nhap xau: ";
		char a;
		int k=0;
		cin>>a;
		do
		{
			if(a==' ') k++;
			else k=0;
			if(k==0) str[count].push_back(a);
			else if(k==1) count++;
			a=getchar();
		}while(a!='\n');
		if(k==0) count++;
	}
	void xuat()
	{
		for(int i=0;i<count;i++)
			cout<<str[i]<<' ';
		cout<<endl;
	}
	void add(stringX p)
	{
		for(int i=0;i<p.count;i++)
			str[count+i]=p.str[i];
		count+=p.count;
	}
	bool exist(string p)
	{
		for(int i=0;i<count;i++)
			if(str[i]==p) return 1;
		return 0;
	}
};
/*
struct array
{
	vector <char> word[100];
	int count;
	void nhap()
	{
		count=0;
		cout<<"Nhap xau : ";
		char a,c;
		cin>>a;
		if(a!='\n'&&a!=' ') word[count].push_back(a);
		while(a!='\n')
		{	
			c=a;//ki tu truoc a
			a=getchar();
			if(c!=' '&&a==' ') count++;
			if(a!='\n'&&a!=' ') word[count].push_back(a);
		}
		if(!word[count].empty()) count++;
	}
	void xuat()
	{
		for(int i=0;i<count;i++) 
		{
			while(!word[i].empty())
			{
				cout<<word[i].back();
				word[i].pop_back();
			}
			cout<<endl;
		}
	}
	int size()
	{
		return count;
	}
};

*/
