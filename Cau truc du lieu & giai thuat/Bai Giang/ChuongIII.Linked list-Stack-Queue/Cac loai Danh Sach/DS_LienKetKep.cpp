//Danh sach lien ket kep
#include <iostream>

using namespace std;

struct node{
	int data;
	node *prev;
	node *next;
};

node *start = NULL;

node *CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->prev=NULL;
	tmp->next=NULL;
	return tmp;
}

void InsertBegin(int value)
{
	node *tmp=CreateNode(value);
	node *p=start;
	if(start == NULL)//neu danh sach chong
	{
		start=tmp;
		start->next=NULL;
		start->prev=NULL;
	}
	else
	{
		tmp->next=p;
		tmp->prev=NULL;
		start=tmp;
	}
}

void InsertLast(int value)
{
	node *tmp=CreateNode(value);
	node *p=start;
	if(start == NULL)
	{
		start=tmp;
		start->next=NULL;
		start->prev=NULL;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=tmp;
		tmp->prev=p;
		tmp->next=NULL;
	}
}

void DeletePos(int pos)
{
	int count=1;
	node *p=start;
	while(p->next != NULL)
	{
		count++;
		p=p->next;
	}
	
}
void Display()
{
	node *p=start;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL";
}

int main()
{
	for(int i=1;i<=4;i++)
	InsertLast(i);
	
	Display();
	return 0;
}
