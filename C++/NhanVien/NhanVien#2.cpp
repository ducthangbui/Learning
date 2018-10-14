#include<fstream>
#include<iostream>
#include"ClassNhanVien.cpp"
using namespace std;
enum Choice{Print=1, Update, New, Delete, End};
int EnterChoice()
{
	//display option
	cout<<endl<<"Enter your choice:"<<endl
		<<"1.Print"<<endl
		<<"2.Update"<<endl
		<<"3.New"<<endl
		<<"4.End"<<endl<<"Choose:";
	int menuChoice;
	cin>>menuChoice;
	return menuChoice;
}
void OutputLine(fstream &output,ClientData record)//Ham in
{
	output<<left<<setw(10)<<record.getFirstName()<<" "
	<<record.getLastName()<<setw(10)<<record.getID()
	<<setw(10)<<record.getAge()<<setw(10)<<record.getSalary();
}
void CreateTextFile(fstream &readFromFile)
{
	//create text file
	fstream outPrintFile("print.txt",ios::out);
	//exit program if cant open file
	if(!outPrintFile)
	{
		cerr<<"File could not open"<<endl;
		exit(1);
	}
	outPrintFile<<left<<setw(10)<<"Name"<<setw(10)<<"ID"<<setw(10)<<"Age"
	<<setw(10)<<right<<"Salary"<<endl;
	//dat vi tri ban dau cua con tro readFromFile de doc file
	//set file-position pointer to begining of readFromFile
	readFromFile.seekg(0);
	//read first reord from file
	//doc ban ghi dau tien tu file 
	ClientData client;
	readFromFile.read(reinterpret_cast<char*>(&client),sizeof(ClientData));
	//copy all records from record file into text file
	//copy tat ca ban ghi tu ban ghi file vao text file
	while(!readFromFile.eof())
	{
		//write single record to text file
		//ghi ban ghi don den text file
		OutputLine(outPrintFile,client);
		//read next record from record file
		//doc ban ghi tiep theo tu ban ghi file
		readFromFile.read(reinterpret_cast<char*>(&client),sizeof(ClientData));
	} 
	
}
void OpenWriteFile()
{
	//open file for reading and writing
	fstream fOfficer("nhanvien.txt",ios::in|ios::out|ios::binary);
	//exit program if cant ope file
	if(!fOfficer)
	{
		cerr<<"File could not open!!!"<<endl;
		exit(1);
	}
	int choice;
	while(choice=EnterChoice()!=End)
	{
		switch(choice)
		{
			case Print: CreateTextFile(fOfficer);//creat text file from record file
						break;
		}
	}
}
void Write()
{
	string FirstName,LastName,ID;
	int age;
	double salary;
	fstream fOfficer("nhanvien.txt",ios::out);
	if(!fOfficer)
	{
		cerr<<"File could not open!!"<<endl;
		exit(1);
	}
	int numberOfficer,dem=0;
	cout<<"Enter Number Officer:";
	ClientData client;
	cin>>numberOfficer;
	while(dem!=numberOfficer)
	{
		cout<<"Enter First Name, Last Name, ID, Age, Salary:"<<endl;
		cin>>FirstName>>LastName>>ID>>age>>salary;
		//set record
		client.setFirstName(FirstName);
		client.setLastName(LastName);
		client.setID(ID);
		client.setAge(age);
		client.setSalary(salary);
		//seek position in file of user-specified record
		fOfficer.seekp((client.get)) 
	}
}
main()
{
	OpenWriteFile();
}
