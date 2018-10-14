#include <iostream>
#include <string.h>
using namespace std;

struct node{
	char *data;
	int count;
	node *next;
	node *prev;
};

node *start=NULL;
node *last=NULL;

node *CreateNode(char *value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->count=1;
	tmp->next=NULL;
	tmp->prev=NULL;
	return tmp;
}
//Add
void Add(char *value)
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
		node *p=start;
		while(p != last)
		{
			if(strcmp(value,p->data) == 0) 
			{
				p->count = (p->count)+1;
				//p=p->next;
				return;
			}
			else
			{
				p=p->next;
			}
		}
		if(strcmp(value,p->data) == 0) 
			{
				p->count = (p->count)+1;
				return;
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
}

void Display()
{
	node *p=start;
	while(p != last)
	{
		cout<<p->data<<" "<<p->count<<endl;
		p=p->next;
	}
	cout<<p->data<<" "<<p->count;
}
main()
{
//	node *T=CreateNode("AB");
	Add("AC");
	Add("AD");
	Add("AE");
	Add("AF");
	
	Add("AB");
	Add("AC");
	Add("AD");
	Add("AE");
	Add("AF");
	
	Add("AB");
	Add("AC");
	Add("AD");
	Add("AE");

	
	Display();
}

