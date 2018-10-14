//Danh sach lien ket kep vong
#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
};

node *start=NULL;

node *CreateNode(int value)
{
	node *tmp= new node;
	tmp->data=value;
	tmp->next=NULL;
	tmp->prev=NULL;
	return tmp;
}

void InsertBegin(int value)
{
	node *tmp=CreateNode(value);
	if(start == NULL)
	{
		start=tmp;
		start->next=start;
		start->prev=start;
	}
	else
	{
		tmp->next=start->next;
		tmp->prev=start->prev;
		start->next=tmp;
		start->prev=tmp;
	}
}

void InsertLast(int value)
{
	node *tmp=CreateNode(value);
	if(start == NULL)
	{
		start=tmp;
		start->next=start;
		start->prev=start;
	}
	else
	{
		tmp->next=start->next;
		tmp->prev=start->prev;
		start->next=tmp;
		start->prev=tmp;
		start=tmp;
	}
}

void InsertPos(int pos,int value)
{
	node *p=start->next;
	for(int i=1;i<pos-1;i++)
	{
		p=p->next;
		if(p == start->next)
		{
			cout<<"So node trong danh sach < "<<pos<<endl;
			return;
		}
	}
	node *tmp=CreateNode(value);
	tmp->next=p->next;
	tmp->prev=p->prev;
	p->next=tmp;
	p->prev=tmp;
	if(p == start) start=p;
}

void Display()
{
	node *p=start->next;
	while(p!=start)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<p->data;
}

main()
{
	for(int i=1;i<=4;i++)
	InsertLast(i);
	
	Display();
	
	int newPos;
	int value;
	cout<<endl<<"Nhap vi tri them node moi:";
	cin>>newPos;
	cout<<endl<<"Nhap gia tri can them:";
	cin>>value;
	InsertPos(newPos,value);
	
	Display();
}
