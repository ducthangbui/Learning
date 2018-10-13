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
} *queue;
void Init(queue &l)
{
	l=NULL;
} 
node *Getnode()
{
	return new node;
}
int Empty(queue &l)
{
	if(l==NULL) return 1;
	return 0;
}
void Push(queue &l,int x)
{
	queue q;
	q=Getnode();
	q->info=x;
	if(Empty(l)) l=q;
	else 
	{
		queue p=l;
		while(p->next!=NULL) p=p->next;
		p->next=q;
	}
}
void Pop(queue &l)
{
	queue p=l;
	if(p==NULL) return ;
	l=l->next;
	delete p;
}
int  Retrieve(queue &a)
{
	if(Empty(a)) return -1;
	return a->info;
}
void Print(queue &l)
{
	queue p=l;
	while(p!=NULL)
	{
		cout<<p->info<<' ';
		p=p->next;
	}
}
main()
{
	queue a;
	Init(a);
	Push(a,1);
	Push(a,2);
	Push(a,3);
	Pop(a);
	Pop(a);
	Pop(a);
	Pop(a);
	
	cout<<Retrieve(a);
	
}
