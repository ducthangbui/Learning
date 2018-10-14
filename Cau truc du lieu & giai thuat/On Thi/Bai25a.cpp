#include <iostream>
#include <string.h>

using namespace std;

struct node{
	char *data;
	int count;
	node *next;
};

node *start=NULL;

//Tao node
node *CreateNode(char *value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->count=1;
	tmp->next=NULL;
	return tmp;
}

//Add
void Add(char *value)
{
	node *p=start;
	node *tmp=CreateNode(value);
	if(start == NULL)
	{
		start=tmp;//Node dau tien la tmp
		start->next=NULL;
	}
	else
	{
		while(p->next != NULL)
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
			p->next=tmp;
			tmp->next=NULL;
		}
	}
}
void Display()//Hien thi
{
	node *p=start;
	while(p!=NULL)
	{
		cout<<p->data<<" "<<p->count<<endl;
		p=p->next;
	}
	cout<<"NULL";
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
