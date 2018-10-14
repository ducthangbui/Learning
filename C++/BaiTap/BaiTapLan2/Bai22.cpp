#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
struct Stack
{
	string data;
	Stack *next;
};
Stack *TaoStack(string s)
{
	Stack *StackMoi=new Stack;
	StackMoi->data=s;
	StackMoi->next=NULL;
	return StackMoi;
}
void push(Stack *head,string s)
{
	Stack *StackThem=TaoStack(s);
	if(head==NULL)
	{
		head=StackThem;;
		return;
	}
	StackThem->next=head;
	head=StackThem;
}
void Xuat(Stack *&head)
{
	Stack *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
}
main()
{
	Stack *head=NULL;
	string s;
	getline(cin,s);
	for(int i=0;i<s.length();i++)
		push(head,s[i]);

	
	Xuat(head);
}
