#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *start=NULL;

//Tao node
node *CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->next=NULL;
	return tmp;
}

//Chen cuoi
void InsertLast(int value)
{
	node *tmp=CreateNode(value);
	node *p=start;
	if(start == NULL)//Neu danh sach rong
	{
		start=tmp;//Node dau tien la tmp
		start->next=NULL;
	}
	else//Neu danh sach khong rong
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=tmp;
		tmp->next=NULL;
	}
}

//Chen dau
void InsertBegin(int value)
{
	node *tmp=CreateNode(value);
	node *p=start;
	if(start == NULL)
	{
		start = tmp;
		start->next=NULL;
	}
	else
	{
		tmp->next=p;
		start=tmp;
	}
}

//Chen vi tri bat ky
void InsertPos(int value,int pos)
{
	int count=1;//Dem so node
	node *tmp=CreateNode(value);
	node *p=start;
	while(p->next!=NULL)
	{
		count++;
		p=p->next;
	}

	if(pos == 1)//Neu pos == count tuc la chen vao cuoi danh sach
	{
		InsertBegin(value);
	}

	else if(pos <= count && pos > 1)
	{
		node *ptr=start;
		for(int i=1;i<pos-1;i++)
		{
			ptr=ptr->next;
		}
		tmp->next=ptr->next;
		ptr->next=tmp;
	}
	else
		cout<<endl<<"Vi tri can chen vuot qua tam kiem soat"<<endl;
}

//Xoa tai vi tri bat ky
void DeleteNode(int pos)
{
	int count=1;
	node *p=start;
	while(p->next!=NULL)
	{
		count++;
		p=p->next;
	}

	if(pos == 1)
	{
		node *ptr=start;
		start=ptr->next;
		delete ptr;
	}
	else if(pos <= count && pos > 1)
	{
		node *ptr=start;
		for(int i=1;i<pos-1;i++)
		ptr=ptr->next;
		node *del=ptr->next;
		ptr->next=del->next;
		delete del;
	}
	else cout<<"Qua tam kiem soat"<<endl;
}

//Sap xep
void Sort()
{
	node *p,*q;
	for(p=start;p!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next)
		if(p->data > q->data)
		{
			int temp=p->data;
			p->data = q->data;
			q->data = temp;
		}
}

void Display()//Hien thi
{
	node *p=start;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL";
}

int main()
{
	for(int i=1;i<=4;i++)
	InsertBegin(i);
	
	Display();
	
	int pos;
	cout<<endl<<"Nhap vi tri can chen:";
	cin>>pos;
	int value;
	cout<<"Nhap gia tri can chen:";
	cin>>value;
	InsertPos(value,pos);
	
	Display();
	
	int delPos;
	cout<<endl<<"Nhap vi tri can xoa:";
	cin>>delPos;
	DeleteNode(delPos);
	
	Display();
	
	cout<<endl<<"Danh sach sau khi sap xep:"<<endl;
	Sort();
	Display();
	return 0;
}
