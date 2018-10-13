#include<iostream>
#include<string>
using namespace std;
class Employee
{
	private:
		string FirstName;
		string LastName;
		int salary;
	public:
		Employee(string fname,string lname,int luong)
		{
			setFirstName(fname);
			setLastName(lname);
			setSalary(luong);
		}
		void setFirstName(string FName)
		{
				FirstName=FName;
		}
		void setLastName(string LName)
		{
				LastName=LName;
		}
		void setSalary(int luong)
		{
				salary=luong;
		}
		string getName()
		{
			return FirstName+LastName;
		}
		int getSalary()
		{
			return salary;
		}
		void Display()
		{
			cout<<"Name:"<<getName()<<endl;
			cout<<"Salary:$"<<getSalary()<<endl;
		}	
};
int main()
{
	Employee Employee1("Ho ","Ten",0);
	cout<<"Enter like prototype:"<<endl;
	Employee1.Display();
	cout<<"------------------------"<<endl;
	string Firstname,LastName;
	int salary;
	cout<<"Enter First Name:";
	getline(cin,Firstname);
	Employee1.setFirstName(Firstname);
	cout<<"Enter Last Name:";
	getline(cin,LastName);
	Employee1.setLastName(LastName);
	cout<<"Enter salary:";
	cin>>salary;
	Employee1.setSalary(salary);
	Employee1.Display();
}
