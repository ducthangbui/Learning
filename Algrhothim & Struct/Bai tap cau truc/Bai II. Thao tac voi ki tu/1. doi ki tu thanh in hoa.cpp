#include <iostream>
using namespace std;

main()
{
	char c;
	cout<<"Bam 1 ki tu : ";
	cin.get(c);
	if(c>='a'&&c<='z') cout<<char(c-32);
	else cout<<c;
}
