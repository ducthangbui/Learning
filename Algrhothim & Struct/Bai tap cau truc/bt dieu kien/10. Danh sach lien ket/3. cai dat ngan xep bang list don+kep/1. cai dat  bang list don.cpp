#include<iostream>
using namespace std;
typedef struct node
{
	int info;
	node *next;
	node()
	{
		info=0;
		next=NULL;
	}
} *stack;
void Init(stack &l)
{
	l=NULL;
} 
node *Getnode()
{
	return new node;
}
int Empty(stack &l)
{
	if(l==NULL) return 1;
	return 0;
}

void Push(stack &l,int x)
{
	stack q;
	q=Getnode();
	q->info=x;
	if(Empty(l)) l=q;
	else 
	{
		stack p=l;
		while(p->next!=NULL) p=p->next;
		p->next=q;
	}
}

void Pop(stack &l)
{
	stack p=l;
	if(p==NULL) return ;
	if(p->next!=NULL)
	{
		while(p->next->next!=NULL)	p=p->next;
		stack q=p->next;
		p->next=NULL;
		delete q;
	}
	else l=NULL;
}
int retrieve(stack &l)
{
	if(l==NULL) return -1;
	stack p=l;
	while(p->next!=NULL) p=p->next;
	return p->info;
}
void Print(stack &l)
{
	stack p=l;
	while(p!=NULL)
	{
		cout<<p->info<<' ';
		p=p->next;
	}
}
main()
{
	stack a;
	Init(a);
	cout<<retrieve(a);
	Print(a);
	
	
}
