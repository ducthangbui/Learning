#include<iostream>
using namespace std;

int isAmstrong(int a){
	int s=0, cs;
	int tmp=a;
	while(tmp!=0){
		cs=tmp%10;
		s+=cs*cs*cs;
		tmp/=10;
	}
	if(a==s) return 1;
	return 0;
}
main(){
	int count=0;
	for(int i=100;i<=999;i++)
	if(isAmstrong(i)){
		count++;
		cout<<i<<" ";
	}
	cout<<"\nCo "<<count<<" so Amstrong co 3 chu so.";
	return 0;
}
