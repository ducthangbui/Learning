/*Chuyen doi so tu nhien tu co so n sang co so b
//Lay du lieu tu file Input.in
//Ghi ket qua ra file Output.in
*/
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int n,b,k;//k la so luong cac test
stack <int> a;

void DoiCoSo()
{
	fstream ifile("Input.in",ios::in);
	fstream ofile("Output.in",ios::out);
		ifile>>k;
		int dem = 0;
		while(dem<k)//co the thay dem<k la !ifile.eof()
	{	
		ifile>>n>>b;
		ofile<<endl<<n<<" "<<b<<" ";
		char x[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
		while (n!=0)
		{
			a.push(n%b);
			n=n/b;
		}
		
		while(!a.empty())
		{
			ofile<<x[a.top()];
			a.pop();
		}
		dem++;
	}
}

int main()
{
	DoiCoSo();
	return 0;
}


