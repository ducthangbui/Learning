#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *head=NULL;

node *CreateNode(int value)
{
	node *tmp;
	tmp = new node;
		tmp->data=value;
		tmp->next=tmp;
		return tmp;
}

void AddLast(int value)
{
	
	//node *tmp;

	node *tmp=CreateNode(value);
	if(head==NULL)
	{
		head=tmp;
	}
	else
	{
		node *p=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		p->next=tmp;
		tmp->next=head;
	}
}

void Display();
void Joseph(int m)
{
	
	while(head->next != head)
	{
	int dem=1;	
		while(dem < m-1)
		{
			head=head->next;
			dem++;
		}
		cout<<"Xoa:"<<head->next->data<<endl;
		node *tmp=head->next;
		head->next=tmp->next;
		head=head->next;
		delete tmp;
	Display();
	}
}
void Display()
{
	node *p=head;
	do
	{
		cout<<p->data<<"->";
		p=p->next;
	} while(p!=head);

}

main()
{
	int n;
	cout<<"Nhap so nguoi n:";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		AddLast(i);
	}
	Display();
	int m;
	cout<<endl<<"Nhap nguoi can xoa thu m:";
	cin>>m;
	Joseph(m);
}
