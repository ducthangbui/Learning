#include<iostream>
#include<cstdlib>
#define MAX 50
using namespace std;
struct queue{
	int front,rear;
	int data[MAX];
	int count;
};
void init(queue &q){
	q.front=0;
	q.rear=-1;
	q.count=0;
}
int empty(queue q){
	if(q.count==0)
		return 1;
	return 0;
}
int full(queue q){
	if(q.count==MAX)
		return 1;
	return 0;
}
void push(queue &q,int x){
	if(full(q)) cout<<"\n hang doi day"<<endl;
	else{
		q.data[++q.rear]=x;
		q.count++;
	}
}
int pop(queue &q){
	if(empty(q)) cout<<"\n hang doi rong"<<endl;
	else{
		int x=q.data[q.front];
		for(int i=q.front;i<q.rear;i++)
			q.data[i]=q.data[i+1];
		q.rear--;
		q.count--;
		return x;
	}
}
int front(queue q){
	if(empty(q)) cout<<"\n hang doi rong"<<endl;
	else return q.data[q.front];
}
void push_circular(queue &q,int x){
	if(full(q)) cout<<"\n hang doi day"<<endl;
	else{
		q.data[(++q.rear)%MAX]=x;
		q.count++;
	}
}
int pop_circular(queue &q){
	if(empty(q)) cout<<"\n hang doi rong"<<endl;
	int x=q.data[q.front];
	q.front=(q.front++)%MAX;
	q.count--;
	return x;
}
void input(queue &q){
	int n,x;
	do{
		cout<<"\n nhap so phan tu cua queue :"<<endl;
		cin>>n;
	}while(n>MAX||n<1);
	for(int i=0;i<n;i++){
		cout<<"\n nhap phan tu thu "<<i+1<<" : ";
		cin>>x;
		push(q,x);
		push_circular(q,x);
	}
}
void output(queue q){
	if(empty(q)) cout<<"\n hang doi rong"<<endl;
	else{
		for(int i=q.front;i<q.rear;i++)
			cout<<q.data[i]<<"  ";
		cout<<"\n";
	}
}
int main(){
	queue q;
	init(q);
	int select,x;
	do{
		system("cls");
		cout<<"\n\a\t\t*********WELCOME TO RUSSIA************\t\t"<<endl;
		cout<<"\n 1. khoi tao queue"<<endl;
		cout<<"\n 2. kiem tra queue rong"<<endl;
		cout<<"\n 3. kiem tra queue day"<<endl;
		cout<<"\n 4. them phan tu vao circular queue"<<endl;
		cout<<"\n 5. xoa phan tu trong circular queue"<<endl;
		cout<<"\n 6. hien thi "<<endl;
		cout<<"\n 0. thoat ra khoi chuong trinh"<<endl;
		cout<<"\n select of you:"<<endl;
		cin>>select;
		switch(select){
			case 1:{
				system("cls");
				input(q);
				system("pause");
				break;
			}
			case 2:{
				system("cls");
				if(empty(q)) cout<<"\n queue rong"<<endl;
				else cout<<"\n queue khong rong"<<endl;
				system("pause");
				break;
			}
			case 3:{
				system("cls");
				if(full(q)) cout<<"\n queue day"<<endl;
				else cout<<"\n queue chua day"<<endl;
				system("pause");
				break;
			}
			case 4:{
				system("cls");
				cout<<"\n nhap phan tu can chen vao queue:"<<endl;
				cin>>x;
				push_circular(q,x);
				system("pause");
				break;
			}
			case 5:{
				system("cls");
				pop_circular(q);
				system("pause");
				break;
			}
			case 6:{
				system("cls");
				output(q);
				system("pause");
				break;
			}
			default:cout<<"\n the victory of us, this is victoryday"<<endl;
		}
	}while(select!=0);
	system("pause");
	return 0;
}
