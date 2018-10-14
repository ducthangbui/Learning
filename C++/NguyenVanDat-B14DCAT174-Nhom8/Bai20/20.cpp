#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void input(string &s){
	s="";
	ifstream fi("input.txt",ios::in);
	if (!fi){
   		cerr << "Khong the mo file doc" << endl;
   		return;
	}
	while (!fi.eof()){
		string tmp;
		getline(fi,tmp);
		s+=tmp;
		s+='\n';
	}
	fi.close();
}

void output(string s){
	ofstream fo("output.txt",ios::out);
	if (!fo){
		cerr << "Khong the mo file ghi" << endl;
   		return;
	}
	fo<<s;
	fo.close();
}

void correct(string &s){
	string s1(".,:;?!)");
	s[0]=toupper(s[0]);//Viet hoa dau van ban
	while(s.find("  ")!=string::npos) s.replace(s.find("  "),2," "); //Xoa 2 dau cach lien nhau
	
	/*Xoa, them dau cach truoc, sau dau cau*/
	for (int i=0; i<s.length(); i++){
		if (s[i]=='\n') s[i+1]=toupper(s[i+1]); //Viet hoa dau doan
		int found=s1.find(s[i]);
		if (found!=string::npos){
			if (s[i+1]!=' ') s.insert(i+1," ");
			if (s[i-1]==' ') s.erase(--i,1);
			if (s1[found]=='.'||s1[found]=='?'||s1[found]=='!'){
				s[i+2]=toupper(s[i+2]); //Viet hoa tu dau cau
			}
		}
		if(s[i]=='('){
			if (s[i+1]==' ') s.erase(i+1,1);
			if (s[i-1]!=' ') {
				s.insert(i," ");
				i+=2;
			}
		}
	}
}

int main(){
	string s;
	input(s);
	correct(s);
	output(s);
	cout<<"Hoan thanh!!!";
	return 0;
}
