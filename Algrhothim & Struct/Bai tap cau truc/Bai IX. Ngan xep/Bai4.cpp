#include<iostream>
#include<stack>
#include<string>
using namespace std;
int hang(char a)
{
	if(a=='*'||a=='/') return 2;
	if(a=='+'||a=='-') return 1;
	if(a=='('||a==')') return 0;
	return -1;
}
void TrungtoSangHauto()
{
	stack <char> T;
	string x;
	cout<<"Nhap vao bieu thuc:";
	getline(cin,x);
	for(int i=0;i<=x.length();i++)
{
	if(x[i]==' ') continue;//loai truong hop dau space dau tien
	if(x[i-1]<'0'||x[i-1]>'9'&&hang(x[i])!=0) cout<<" ";
	if(x[i]>='0'&&x[i]<='9') cout<<x[i];//Neu la so thi in ra m,an hinh
	else if(x[i]==')' || x[i]==NULL)
	{
		while(!T.empty())
		{
			if(T.top()!='(') cout<<" "<<T.top();
			T.pop();
		}
	}	
	else if(hang(x[i])!=-1)//truong hop cac toan tu thi push vao stack
		{
			if(T.empty()) T.push(x[i]);//push ( vao stack dau tien
			else
			{
				if(x[i]!='(' && hang(x[i])<=hang(T.top()))//in cac toan tu
				{
					cout<<" "<<T.top();
					T.pop();
				}
				T.push(x[i]);
			}
		}
	}
}

main()
{
	TrungtoSangHauto();
}
