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
} *Queue;
void Init(Queue &l)
{
	l=NULL;
} 
node *Getnode()
{
	return new node;
}
int Empty(Queue &l)
{
	if(l==NULL) return 1;
	return 0;
}

void Push(Queue &l,int x)
{
	Queue q;
	q=Getnode();
	q->info=x;
	if(Empty(l)) l=q;
	else 
	{
		Queue p=l;
		while(p->next!=NULL) p=p->next;
		p->next=q;
	}
}

int Pop(Queue &l)
{
	Queue p=l;
	int k=p->info;
	if(p==NULL) return -1;
	l=l->next;
	delete p;
	return k;
}
int Retrieve(Queue &l)
{
	if(!Empty(l)) return l->info;
	else return -1;
}
void Print(Queue &l)
{
	Queue p=l;
	while(p!=NULL)
	{
		cout<<p->info<<' ';
		p=p->next;
	}
}
main()
{
	Queue a;
	Init(a);
	Push(a,1);
	Push(a,2);
	Push(a,5);
	Push(a,6);
	Push(a,7);
	Pop(a);
	cout<<Retrieve(a);
}
