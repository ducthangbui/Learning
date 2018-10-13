#include <iostream>
using namespace std;

main()
{
	char c;
	cout<<"Bam 1 ki tu : ";
	cin.get(c);
	if(c>='A'&&c<='Z') cout<<char(c+32);
	else cout<<c;
}
