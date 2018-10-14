#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void input(string &text){
	text="";
	ifstream fi("input.txt",ios::in);
	if (!fi){
		cerr<<"Khong mo duoc tep doc"<<endl;
		return;
	}
	while (!fi.eof()){
		string tmp;
		getline(fi,tmp);
		text+=tmp;
		text+='\n';
	}
	fi.close();
}

void output(string text){
	ofstream fo("output.txt",ios::out);
	if (!fo){
		cerr<<"Khong mo duoc tep ghi"<<endl;
		return;
	}
	fo<<text;
	fo.close();
}

void translate(string &text){
	ifstream dict("dictionary.txt");
	if (!dict){
		cerr<<"Khong co file tu dien"<<endl;
		return;
	}
	while (!dict.eof()){
		string teencode, meaning;
		dict>>teencode>>meaning;
		teencode.insert(0," ");
		meaning.insert(0," ");
		int pos;
		do{
			pos=text.find(teencode);
			if (pos!=string::npos){
				text.erase(pos,teencode.length());
				text.insert(pos,meaning);
			}
		} while (pos!=string::npos);
	}
	dict.close();
}

int main(){
	string txt;
	input(txt);
	cout<<"Dang dich..."<<endl;
	translate(txt);
	output(txt);
	cout<<"Hoan thanh..."<<endl;
	return 0;
}
