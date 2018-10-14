#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
};

node *start=NULL;
node *last=NULL;

node *CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->next=NULL;
	tmp->prev=NULL;
	return tmp;
}

void InsertBegin(int value)
{
	node *tmp=CreateNode(value);
	if(start == NULL && last == NULL)
	{
		start=last=tmp;
		start->next=last->next=NULL;
		start->prev=last->prev=NULL;
	}
	else
	{
		tmp->next=start;
		start->prev=tmp;
		start=tmp;
		start->prev=last;
		last->next=start;
	}
}

void InsertLast(int value)
{
	node *tmp=CreateNode(value);
	if(start == NULL && last == NULL)
	{
		start=last=tmp;
		start->next=last->next=NULL;
		start->prev=last->prev=NULL;
	}
	else
	{
		last->next=tmp;
		tmp->prev=last;
		last=tmp;
		last->next=start;
		start->prev=last;
	}
}

void InsertPos(int pos,int value)
{
	int count=1;
	node *p=start;
	while(p != last)
	{
		count++;
		p=p->next;
	}
//	cout<<endl<<"Count:"<<count<<endl;
	if(pos == 1) InsertBegin(value);
//	else if(pos == count) InsertLast(value);
	else if(pos > 1 && pos <= count)
	{
		node *ptr=start;
		node *tmp=CreateNode(value);
		for(int i=1;i<pos;i++)
		{
		//	cout<<endl<<"ptr->data:"<<ptr->data<<" ";
			ptr=ptr->next;
		}
		node *ptr2=ptr;
	//	cout<<endl<<"ptr2->data:"<<ptr2->prev->data<<endl;
		ptr->prev->next=tmp;
		tmp->next=ptr2;
		tmp->prev=ptr2->prev;
		ptr2->prev=tmp;
	}
}

void DeletePos(int pos)
{
	int count=1;
	node *p=start;
	while(p!=last)
	{
		count++;
		p=p->next;
	}
	
	if(pos == 1)
	{
		node *ptr=start;
		last->next=ptr->next;
		ptr->next->prev=last;
		start=ptr->next;
		delete ptr;
		return;
	}
	
	if(pos == count)
	{
		node *ptr=last;
	//	cout<<endl<<"ptr->prev->data:"<<last->data<<endl;;
		ptr->prev->next=start;
		start->prev=ptr->prev;
		last=ptr->prev;
		delete ptr;
		return;	
	}
	
	if(pos > 1 && pos < count)
	{
		node *ptr=start;
		for(int i=1;i<pos;i++)
		ptr=ptr->next;
		node *del=ptr;
		del->prev->next=del->next;
		del->next->prev=del->prev;
		delete del;
		return;
	}
}
void Display()
{
	node *p=start;
	while(p != last)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<p->data;
}

main()
{
	for(int i=1;i<=5;i++)
	InsertLast(i);
	
	Display();
	
	cout<<endl;
	InsertPos(5,20);
	Display();
	
	cout<<endl;
	DeletePos(6);
	Display();
}
