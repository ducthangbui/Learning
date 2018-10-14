#include "bandoc.h" // class's header file

// class constructor
BanDoc::BanDoc()
{
	// insert your code here
}
BanDoc::BanDoc(char *name,char *add,int phonenumber)
{
	maThe = gerMaThe++;
	strcpy(hoten,name);
	strcpy(diachi,add);
	sdt = phonenumber;
	
}

int BanDoc::gerMaThe=10000;


