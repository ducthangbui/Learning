#include <iostream>
#include <string.h>
using namespace std;

struct node{
	char *data;
	int count;
	node *next;
};

node *last=NULL;

node *CreateNode(char *value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->count=1;
	tmp->next=tmp;
	return tmp;
}

//Add
void Add(char *value)
{

	node *tmp=CreateNode(value);
	if(last == NULL)
	{
		last=tmp;//Node dau tien la tmp
		last->next=last;
	}
	else
	{
		node *p=last->next;
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
			tmp->next=last->next;
			last->next=tmp;
			last=tmp;
		}
	}
}

void Display()
{
	node *p=last->next;
	while(p != last)
	{
		cout<<p->data<<" "<<p->count<<endl;
		p=p->next;
	}
	cout<<p->data<<" "<<p->count<<endl;
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
