#include<iostream>
#include<string>
#include<math.h>
#include<stack>
using namespace std;

void input(string &postfix){
	cout<<"Nhap vao bieu thuc hau to: ";
	getline(cin,postfix);
}

int priority(char a){
	if ('+'==a||'-'==a) return 1;
	if ('*'==a||'/'==a||'%'==a) return 2;
	if ('^'==a) return 3;
	return 0;
}

int cal(string postfix){
	stack <int> a;
	for(int i=0; i<postfix.length(); i++){
		if (postfix[i]==' ') break;
		else if (isdigit(postfix[i])){
			a.push(postfix[i]-'0');
		}
		else{
			int x, y;
			x=a.top(); a.pop();
			y=a.top(); a.pop();
			if (postfix[i]=='+') a.push(y+x);
			else if (postfix[i]=='-') a.push(y-x);
			else if (postfix[i]=='*') a.push(y*x);
			else if (postfix[i]=='/') a.push(y/x);
			else if (postfix[i]=='%') a.push(y%x);
			else if (postfix[i]=='^') a.push(pow(y,x));
		}
	}
	return a.top();
}

void output(int a){
	cout<<"Gia tri cua bieu thuc la: "<<endl;
	cout<<a;
}

int main()
{
	string postfix;
	input(postfix);
	output(cal(postfix));
	return 0;
}
