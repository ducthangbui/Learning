#include<iostream>
#include<string>
#include<stack>
#define MAX 50
using namespace std;

void input(string &s){
	cout<<"Nhap vao dong ky tu: ";
	getline(cin,s);
}

void revert(string &s){
	stack <char> a;
	char c;
	int n=s.length();
	int i=0;
	while (i<n){
		a.push(s[i]);
		i++;
	}
	while (!a.empty()){
		c=a.top();
		a.pop();
		cout<<c;
	}
}
int main(){
	string s;
	input(s);
	revert(s);
	return 0;
}
