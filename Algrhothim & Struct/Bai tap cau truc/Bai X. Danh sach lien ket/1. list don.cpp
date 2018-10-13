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
} *list;
void Init(list &l)
{
	l=NULL;
} 
node *Getnode()
{
	return new node;
}
int Empty(list &l)
{
	if(l==NULL) return 1;
	return 0;
}
void Add_Left(list &l,int x)
{
	list p;
	p=Getnode();
	p->info=x;
	p->next=l;
	l=p;
}
void Add_Right(list &l,int x)
{
	list q;
	q=Getnode();
	q->info=x;
	if(Empty(l)) l=q;
	else 
	{
		list p=l;
		while(p->next!=NULL) p=p->next;
		p->next=q;
	}
}
void Add_After(list &l,int x,int y)
{
	list q=l;
	while(q!=NULL&&q->info!=x) q=q->next;
	if(q==NULL) return ;
	if(q->info==x)
	{
		list p;
		p=Getnode();
		p->info=y;
		p->next=q->next;
		q->next=p;
	}
}
void Del_Right(list &l)
{
	list p=l;
	if(p==NULL) return ;
	if(p->next!=NULL)
	{
		while(p->next->next!=NULL)	p=p->next;
		list q=p->next;
		p->next=NULL;
		delete q;
	}
	else l=NULL;
}
void Del_Left(list &l)
{
	list p=l;
	if(p==NULL) return ;
	l=l->next;
	delete p;
}
void Del_After(list &l,int x)
{
	list p=l;
	while(p!=NULL&&p->info!=x) p=p->next;
	if(p==NULL) return; 
	if(p->next==NULL) return;
	list q=p->next;
	p->next=NULL;
	delete q;
}
void Print(list &l)
{
	list p=l;
	while(p!=NULL)
	{
		cout<<p->info<<' ';
		p=p->next;
	}
}
main()
{
	
}