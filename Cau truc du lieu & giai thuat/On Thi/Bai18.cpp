#include<iostream>
using namespace std;
struct node{
	int info;
	node *next;
	node *prev;
}*head,*tail;
class dqueue{
	public:
		int top1,top2;
		void insertfront();
		void insertlast();
		void delfront();
		void dellast();
		void displayfront();
		void displaylast();
		dequeue(){
			top1=0;
			top2=0;
			head=NULL;
			tail=NULL;
		}
};
void dqueue::insertfront(){
	node *p;
	int x;
	if(top1+top2>=50){
		cout<<"\n tran hang doi"<<endl;
		return ;
	}
	if(top1+top2==0){
		cout<<"\n nhap gia tri node:"<<endl;
		cin>>x;
		head=new node;
		head->info=x;
		head->next=NULL;
		head->prev=NULL;
		tail=head;
		top1++;
	}
	else{
		cout<<"\n nhap gia tri node:"<<endl;
		cin>>x;
		p=new node;
		p->info=x;
		p->next=head;
		p->prev=NULL;
		head->prev=p;
		head=p;
		top1++;
	}
}
void dqueue::insertlast(){
	node *p;
	int x;
	if(top1+top2>=50){
		cout<<"\n tran hang doi"<<endl;
		return ;
	}
	if(top1+top2==0){
		cout<<"\n nhap gia tri node:"<<endl;
		cin>>x;
		head=new node;
		head->info=x;
		head->next=NULL;
		head->prev=NULL;
		tail=head;
		top1++;
	}
	else{
		cout<<"\n nhap gia tri node:"<<endl;
		cin>>x;
		p=new node;
		p->info=x;
		p->next=NULL;
		p->prev=tail;
		tail->next=p;
		tail=p;
		top2++;
	}
}
void dqueue::delfront(){
	node *p=head;
	if(top1+top2<=0){
		cout<<"\n dqueue rong"<<endl;
		return ;
	}
	head=head->next;
	head->prev=NULL;
	top1--;
	delete p;
}
void dqueue::dellast(){
	node *p=tail;
	if(top1+top2<=0){
		cout<<"\n dqueue underflow"<<endl;
		return ;
	}
	tail=tail->prev;
	tail->next=NULL;
	top2--;
	delete p;
}
void dqueue::displayfront(){
	node *p;
	if(top1+top2<=0){
		cout<<"\n dqueue rong"<<endl;
		return ;
	}
	p=head;
	cout<<"\n bat dau duyet tu node dau:"<<endl;
	while(p!=NULL){
		cout<<p->info<<" ";
		p=p->next;
	}
}
void dqueue::displaylast(){
	node *p;
	if(top1+top2<=0){
		cout<<"\n hang doi rong"<<endl;
		return ;
	}
	cout<<"\n duyet tu node cuoi:"<<endl;
	p=tail;
	while(p!=NULL){
		cout<<p->info<<"  ";
		p=p->prev;
	}
}
int main(){
	
}
//copyright by PHAN ANH LE
