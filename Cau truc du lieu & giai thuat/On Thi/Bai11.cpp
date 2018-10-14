#include <iostream>
#define MAX 1000

using namespace std;

struct queue{
	int inp;//con tro inp bieu dien loi vao cua hang doi
	int out;//con tro out bieu dien loi ra cua hang doi
	int node[MAX];
};

bool Empty(queue *q)
{
	if(q->inp == q->out) return true;//neu day thi tra ve gia tri true
							return false;//neu k day thi tra v e gia tri flase
}

bool Full(queue *q)
{
	if(q->inp == MAX-1) return true;
						return false;
}

void Push(queue *q,int x)//x la du lieu them vao queue
{
	if(!Full(q))
	{
		q->inp=(q->inp)+1;
		q->node[q->inp]=x;
	}
	else cout<<"Queue day"<<endl;
}

int Top(queue *q)
{
	if(!Empty(q))
	{
		int x=q->node[q->inp];
		//q->inp=(q->inp)-1;
		return x;
	}
	else cout<<endl<<"Queue rong"<<endl;
}

void Pop(queue *q)
{
	if(!Empty(q))
	{
		q->out=(q->out)+1;
	}
	else cout<<endl<<"Queue rong"<<endl;
}

int Size(queue *q)
{
	return (q->inp)+1;
}

void Display(queue *q)
{
	while(!Empty(q))
	{
		q->out=(q->out)+1;
		cout<<q->node[q->out]<<" ";
		//Pop(q);
	}
}

main()
{
	queue *q;
	q->inp=-1;
	q->out=-1;
	for(int i=1;i<=10;i++)
	Push(q,i);
	
	cout<<endl<<"Size:"<<Size(q)<<endl;
	cout<<"Queue:";
	Display(q);
}

