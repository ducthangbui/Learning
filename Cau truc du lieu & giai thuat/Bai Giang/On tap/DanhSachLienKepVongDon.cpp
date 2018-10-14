#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *last=NULL;

node *CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->next=tmp;
	return tmp;
}

void InsertBegin(int value)
{
	node *tmp=CreateNode(value);
	if(last == NULL)
	{
		last=tmp;
		last->next=last;
	}
	else
	{
		tmp->next=last->next;
		last->next=tmp;
	}
}

void InsertLast(int value)
{
	node *tmp=CreateNode(value);
	if(last == NULL)
	{
		last=tmp;
		last->next=last;
	}
	else
	{
		tmp->next=last->next;
		last->next=tmp;
		last=tmp;
	}
}

void InsertPos(int value,int pos)
{
	node *p=last->next;
	for(int i=1;i<pos-1;i++)
	{
		p=p->next;
		if(p == last->next)
		{
			cout<<"So node trong danh sach < vi tri "<<pos<<endl;
			return;
		}
	}
	node *tmp=CreateNode(value);
	tmp->next=p->next;
	p->next=tmp;
	if(p == last) last=tmp;
}

void DeletePos(int pos)
{
	int count=1;
	node *p=last->next;
	while(p != last)
	{
		count++;
		p=p->next;
	}
	
	if(pos == 1)
	{
		node *ptr=last->next;
		last->next=ptr->next;
		delete ptr;
		return;
	}
	
	if(pos == count)
	{
		node *s=last->next;
		for(int i=1;i<pos-1;i++)
		s=s->next;
		node *ptr=s->next;
		s->next=last->next;
		delete ptr;
		last=s;
		return;
	}
	
	if(pos > 1 && pos < count)
	{
		node *ptr=last;
		for(int i=1;i<=pos-1;i++)
		ptr=ptr->next;
		node *del=ptr->next;
		ptr->next=del->next;
		delete del;
		return;
	}
	
}

void Display()
{
	node *p=last->next;
	while(p != last)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<p->data<<" ";
}

main()
{
	for(int i=1;i<=5;i++)
	InsertLast(i);
	Display();
	
	cout<<endl;
	DeletePos(2);
	Display();
}
