#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int RandomDigit1()
{
	int n;
	srand((int)(time(0)));
	n=rand()%10;
	return n;
}
int RandomDigit2()
{
	int a;
	srand((int)(time(0)));
	a=rand()%11+1;
	return a;
}
int RandomDigit3()
{
	int n;
	srand((int)(time(0)));
	n=rand()%90+10;
	return n;
}
int RandomDigit4()
{
	int a;
	srand((int)(time(0)));
	a=rand()%90+10;
	return a;
}
void right(int a)
{
	switch(a)
	{
		case 1: cout<<"Rat tot"<<endl;break;
		case 2: cout<<"Xuat sac"<<endl; break;
		case 3: cout<<"Lam tot lam"<<endl; break;
		case 4: cout<<"Hay lam tot tiep nhe"<<endl; break;
	}
}
void wrong(int a)
{
	switch(a)
	{
		case 1: cout<<"Sai, hay thu lai nhe"<<endl; break;
		case 2: cout<<"Sai, thu lai mot lan nua"<<endl; break;
		case 3: cout<<"Dung bo cuoc"<<endl; break;
		case 4: cout<<"Sai, hay tiep tuc co gang"<<endl; break;
	}
}
void Program();
void Level2()
{
	int dung=0,sai=0;
	for(int i=0;i<10;i++)
	{
		int a=RandomDigit3();
		int b=RandomDigit4();
		cout<<a<<" nhan "<<b<<" bang ?"<<endl;
		cout<<"Nhap dap an:";
		int dapan;
		cin>>dapan;	
		if(a*b==dapan) right(rand()%4+1),dung++;
		else wrong(rand()%4+1),sai++;
	}	
		if(sai/10<7.5) cout<<endl<<"Hay hoi giao vien de duoc tro giup them"<<endl;
		else cout<<endl<<"Chuc mung ban,ban co the sang level tiep theo"<<endl;
	
}
void Level1()
{
	int dung=0,sai=0;
	for(int i=0;i<10;i++)
	{
		int a=RandomDigit1();
		int b=RandomDigit2();
		cout<<a<<" nhan "<<b<<" bang ?"<<endl;
		cout<<"Nhap dap an:";
		int dapan;
		cin>>dapan;	
		if(a*b==dapan) right(rand()%4+1);
		else wrong(rand()%4+1),sai++;
	}	
		if((sai/10)<7.5) 
		{
			system("cls");
		cout<<endl<<"Hay hoi giao vien de duoc tro giup them"<<endl;
		Program();
		}
		else 
		{
			system("cls");
			cout<<endl<<"Chuc mung ban,ban co the sang level tiep theo"<<endl;
			Level2();
		}
	
}
void Program()
{
	
	cout<<"1.Level 1"<<endl;
	cout<<"2.Level 2"<<endl;
	cout<<"Nhap Level:"<<endl;
	int a;
	cin>>a;
	switch(a)
	{
		case 1: system("cls"),Level1(); break;
		case 2:	system("cls"),Level2();break;
	}
}
main()
{
	Program();
}
