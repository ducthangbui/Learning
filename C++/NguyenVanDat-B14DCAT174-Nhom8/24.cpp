#include<iostream>
#include<string>
#include<stack>
#define MAX 50
using namespace std;

void input(char ex[]){
	cout<<"Nhap vao bieu thuc trung to (khong nhap dau cach): ";
	cin>>ex;
}

int priority(char a){
	if ('+'==a||'-'==a) return 1;
	if ('*'==a||'/'==a||'%'==a) return 2;
	if ('^'==a) return 3;
	return 0;
}

void infix2postfix(char ex[], string &postfix){
	int len=strlen(ex);
	postfix="";
	ex[len]=')';
	ex[++len]=0;
	stack <char> a;
	a.push('(');
	for (int i=0; i<len; i++){
		if(isdigit(ex[i])){
			postfix+=ex[i];
			postfix+=' ';
		}
		else if(ex[i]=='(') a.push('(');
			else if(ex[i]==')'){
			char c=0;
			while(a.top()!='('){
				c=a.top();
				a.pop();
				postfix+=c;
				postfix+=' ';
			}
			a.pop();
		}
		else if(priority(ex[i])!=0){
			char c=0;
			while (priority(ex[i])<=priority(a.top())){
				c=a.top();
				a.pop();
				postfix+=c;
				postfix+=' ';
			}
			a.push(ex[i]);		
			}
	}
}

void output(string postfix){
	cout<<"Bieu thuc hau to la: "<<endl;
	cout<<postfix;
}

int main()
{
	char ex[MAX];
	string postfix;
	input(ex);
	infix2postfix(ex,postfix);
	output(postfix);
	return 0;
}
