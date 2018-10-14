//hang doi vong bang mang
#include <iostream>
#define MAX 1000 
using namespace std;

int cqueueArray[MAX];
int front=-1;
int rear=-1;

void Push(int item)
{
	if((front == 0 && rear == -1) || (front == rear+1))
	{
		cout<<"tran hang doi"<<endl;
		return;
	}
	if(front == -1 )
	{
		front = 0;
		rear = 0;
	}
	else 
	{
		if(rear == MAX-1) rear=0;
		else rear++;
	}
	cqueueArray[rear]=item;
}

void Pop()
{
	if(front == -1)
	{
		cout<<"Queue rong"<<endl;
		return;
	}
	cout<<"Phan tu bi loai bo la:"<<cqueueArray[front]<<endl;
	if(front == rear) 
	{
		front=-1;
		rear=-1;
	}
	else
	{
		if(front == MAX-1) front=0;
		else front++;
	}
}

void Display()
{
	int frontPos=front;
	int rearPos=rear;
	if(front == -1) 
	{
		cout<<"hang doi rong"<<endl;
		return;
	}
	cout<<"cac phan tu cua hang doi:";
	if(frontPos <= rearPos)
	{
		while(frontPos <= rearPos)
		{
			cout<<cqueueArray[frontPos]<<" ";
			frontPos++;
		}
	}
	else
	{
		while(frontPos <= MAX-1)
		{
			cout<<cqueueArray[frontPos]<<" ";
			frontPos++;
		}
		frontPos=0;
		while(frontPos <= rearPos)
		{
			cout<<cqueueArray[frontPos]<<" ";
			frontPos++;
		}
	}
	cout<<endl;
}

main()
{
	for(int i=1;i<=4;i++)
	Push(i);
	Display();
	Pop();
	Display();
}
