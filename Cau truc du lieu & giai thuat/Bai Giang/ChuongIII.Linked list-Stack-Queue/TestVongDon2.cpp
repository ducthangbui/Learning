#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *last=NULL;

void CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	if(last == NULL){
		last=tmp;
		tmp->next=last;
	}	
	else
	{
		tmp->next=last->next;
		last->next=tmp;
		last=tmp;
	}
}

void Display()
{
	node *p=last->next;
	while(p!=last)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<p->data<<endl;
}

main()
{
	for(int i=1;i<=3;i++)
	CreateNode(i);
	Display();
}
