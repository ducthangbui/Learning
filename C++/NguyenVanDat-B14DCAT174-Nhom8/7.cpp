#include<iostream>
#include<math.h>
using namespace std;

void display(){
	for(int i=0;i<=10;i++){
		cout<<i<<"	"<<pow(i,2)<<"	"<<pow(i,3)<<endl;
	}
}

int main(){
	display();
	return 0;
}
