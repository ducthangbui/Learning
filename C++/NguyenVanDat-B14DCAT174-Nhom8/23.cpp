#include<iostream>
#include<string>
#include<stack>
#define MAX 50
using namespace std;

void input(string &s){
	cout<<"Nhap vao dong ky tu: ";
	getline(cin,s);
	for (int i=0; i<s.length(); i++){
		s[i]=toupper(s[i]);
	}
}

void getwords(string s, string word[]){
	char * cstr = new char [s.length()+1];
	strcpy (cstr, s.c_str());
	char * p = strtok (cstr," ,.!?:;");
	int i=0;
	while (p!=0)
	{
	   word[i].assign(p);
	   p = strtok(NULL," ,.!?:;");
	   i++;
	}
	delete[] cstr;
}

void words2string(string &s, string word[]){
	int i=0;
	while (word[i]!="") {
		s+=word[i];
		i++;
	}
}

void revert_sentence(string word[], string &s){
	stack <string> a;
	string c;
	int i=0;
	while (word[i]!=""){
		a.push(word[i]);
		i++;
	}
	while (!a.empty()){
		c=a.top();
		s+=c;
		a.pop();
	}
}
int main(){
	string s, s1, s2;
	string word[MAX];
	input(s);
	getwords(s, word);
	words2string(s1, word);
	revert_sentence(word, s2);
	if (s1==s2) cout<<"Xau doi xung";
	else cout<<"Xau bat doi xung";
	return 0;
}
