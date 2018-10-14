#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
main()
{
	srand((int)(time(0)));
	int a=rand()%4;
	cout<<a;
}
