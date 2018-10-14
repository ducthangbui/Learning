#include<fstream>
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
class ClientData//class Nhan Vien
{
	public:
		//Contructor
		ClientData(string="",string="",int=0,double=0.0);
		void setFirstName(string Fname)
		{
			FirstName=Fname;
		}
		string getFirstName()
		{
			return FirstName;
		}
		void setLastName(string Lname)
		{
			LastName=Lname;
		}
		string getLastName()
		{
			return LastName;
		}
		void setID(string code)
		{
			ID=code;
		}
		string getID()
		{
			return ID;
		}
		void setSalary(double S)
		{
			salary=S;
		}
		double getSalary()
		{
			return salary;
		}
		void setAge(int A)
		{
			age=A;
		}
		int getAge()
		{
			return age;
		}
	private:
		string FirstName,LastName,ID;
		int age;
		double salary;
};
