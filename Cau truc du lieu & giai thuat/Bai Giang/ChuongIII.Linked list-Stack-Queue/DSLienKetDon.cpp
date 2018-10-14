#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	node *next;
};

node *CreateNode(int value)
{
	node *tmp;
	tmp = new node;
	if(tmp == NULL)
	{
		cout<<"Khong du khong gian bo nho de cap phat"<<endl;
		return 0;
	}
	else
	{
		tmp->data=value;
		tmp->next=NULL;
		return tmp;
	}
}

node *start=NULL;

void InsertBegin()
{
	node *tmp,*p;
	int value;
	cout<<"Nhap vao gia tri can them:";
	cin>>value;
	tmp=CreateNode(value);
	if(start == NULL)
	{
		start=tmp;
		start->next=NULL;
	}
	else
	{
		p=start;
		start=tmp;
		start->next=p;
	}
	cout<<"Hoan thanh them node vao danh sach"<<endl;
}

void InsertLast()
{
	node *tmp,*p;
	int value;
	cout<<"Nhap gia tri can them:";
	cin>>value;
	tmp=CreateNode(value);
	if(start==NULL)
	{
		cout<<"danh sach rong"<<endl;
		return;
	}
	else
	{
		p=start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=tmp;
		tmp->next=NULL;
		cout<<"Hoan thanh them vao cuoi danh sach"<<endl;
	}
}

void InsertPos()
{
	node *tmp,*p;
	int value,pos;
	cout<<"Nhap gia tri can them:";
	cin>>value;
	tmp=CreateNode(value);
	cout<<"Nhap vi tri can them:";
	cin>>pos;
	int count=0;
	p=start;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	if(pos <= count)
	{
		if(pos == 1) 
		{
			p=start;
			start=tmp;
			start->next=p;
		}
		else if (pos == count)
		{
			p=start;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=tmp;
			tmp->next=NULL;
		}
		else
		{
			p=start;
			for(int i=1;i<pos-1;i++)
			p=p->next;
			tmp->next=p->next;
			p->next=tmp;
		}
	}
	else
	{
		cout<<"Vuot khoi vung kiem soat"<<endl;
		return;
	}
}

void DeletePos()
{
	node *tmp,*p;
	int pos;
	cout<<endl<<"Nhap vi tri can xoa:";
	cin>>pos;
	int count=0;
	p=start;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	if(pos<=count)
	{
		if(pos==1) 
		{
			p=start;
			start=p->next;
			p->next=NULL;
			free(p);
		}
		else if(pos == count)
		{
			p=start;
			while(p->next->next != NULL)
			{
				p=p->next;
			}
			node *tam=p->next;
			p->next=NULL;
			tam->next=NULL;
			free(tam);
		}
		else
		{
			p=start;
			for(int i=1;i<pos-1;i++)
			p=p->next;
			node *tam=p->next;
			p->next=tam->next;
			tam->next=NULL;
			free(tam);
		}
	}
	else
	{
		cout<<endl<<"Vuot qua vugn kiem soat"<<endl;
		return;
	}
	
}

void Search()
{
	int value;
	cout<<"Nhap gia tri can tim:";
	cin>>value;
	node *p=start;
	bool flag;
	while(p!=NULL)
	{
		if(p->data == value) flag=true;
		p=p->next;
	}
	if(flag == true) cout<<"Da tim thay"<<endl;
	else if(flag == false ) cout<<"K co"<<endl;
}

void Sort()
{
	node *p=start;
	node *ptr;
	int value;
	for(p=start;p!=NULL;p=p->next)
		for(ptr=p->next;ptr!=NULL;ptr=ptr->next)
		{
			if(p->data > ptr->data)
			{
				value=p->data;
				p->data=ptr->data;
				ptr->data=value;	
			}
		}
}

void Display()
{
	node *p;
	p=start;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL";
}

main()
{
	for(int i=1;i<=3;i++)
	InsertBegin();
	InsertLast();
	InsertPos();
	Display();
	DeletePos();
	Display();
}
