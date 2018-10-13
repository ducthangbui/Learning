#include <iostream>

using namespace std;

struct node{
	int doUuTien;
	int data;
	node *next;
};

node *head=NULL;
	
node *CreateNode(int value,int doUuTien)
{
	node *tmp = new node;
	tmp->data=value;
	tmp->doUuTien=doUuTien;
	tmp->next=NULL;
	return tmp;
}

void Sort()
{
	for(node *i=head;i!=NULL;i=i->next)
		for(node *j=i->next;j!=NULL;j=j->next)
		{
			if(i->data < j->data)
			{
				node *tmp=i;
				i=j;
				j=tmp;
			}
		}	
}

void Push(int value,int doUuTien)
{
	node *tmp=CreateNode(value,doUuTien);
	if(head == NULL)
	{
		head=tmp;
		head->next=NULL;
	}
	else 
	{
		node *p=head;
		tmp->next=p;
		head=tmp;
	}
	
	Sort();	
}

void Pop()
{
//	Sort();
	node *p=head;
	head=p->next;
	delete p;
}

void Display()
{
//	Sort();
	node *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
}
main()
{
	int value,doUuTien;
	for(int i=1;i<=3;i++)
	{
		cout<<"Nhap gia tri:";
		cin>>value;
		cout<<"Nhap do uu tien:";
		cin>>doUuTien;
		Push(value,doUuTien);
	}
	
	Display();
	
	cout<<endl;
	Pop();
	Display();
	
	
}
