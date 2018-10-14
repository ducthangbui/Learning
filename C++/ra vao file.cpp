#include<iostream>
#include<fstream>//Phai khai bao thu vien nay
using namespace std;
main()
{
	fstream tenFile;
	tenFile.open("demo.txt",ios::out|ios::in);
	//mo tep tin co de doc
	//ios::out dung de ghi file
	//ios::in dung de doc file
	tenFile<<"Em La Gio"<<endl;//Ghi vao File
	
}
