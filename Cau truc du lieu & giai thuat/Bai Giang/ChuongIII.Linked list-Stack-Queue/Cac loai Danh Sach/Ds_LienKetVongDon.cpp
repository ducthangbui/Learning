//danh sach lien ket don vong
#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
};

node *last=NULL;

node *CreateNode(int value)
{
	node *tmp = new node;
	tmp->data = value;
	tmp->next=tmp;
	return tmp;
}

void InsertBegin(int value)
{
	node *tmp = CreateNode(value);
	if(last == NULL)
	{
		last=tmp;
		last->next=last;
	}
	else
	{
		tmp->next=last->next;
		last->next=tmp;
	}
}

void InsertLast(int value)
{
	node *tmp = CreateNode(value);
	if(last == NULL)
	{
		last = tmp;
		last->next=last;
	}
	else
	{
		tmp->next=last->next;
		last->next=tmp;
		last=tmp;
	}
}

void InsertPos(int value,int pos)
{
	
	node *p=last->next;
	for(int i=1;i<pos-1;i++)
	{
		p=p->next;
		if(p == last->next)//quay ve vi tri ban dau khi duyet
			{
				cout<<"So node trong danh sach < vi tri "<<pos<<endl;
				return;
			}
	}
	if(pos == 1)
	{
		InsertBegin(value);	
	}
	
	node *tmp=CreateNode(value);
	tmp->next=p->next;
	p->next=tmp;
	if(p==last) last=tmp;
}

void DeletePos(int pos)
{
	int count=1;
	node *p=last->next;
	while(p!=last)
	{
		count++;
		p=p->next;
	}
	
	if(pos==1)
	{
		node *ptr=last->next;
		last->next=ptr->next;
		delete ptr;
		return;
	}
	else if(pos == count)
	{
		node *s=last->next;
		for(int i=1;i<pos-1;i++)
		s=s->next;
		node *ptr=s->next;
		s->next=last->next;
		delete ptr;
		last=s;
		return;
	}
	else if(pos < count && pos >1)
	{
		node *ptr=last;
		for(int i=1;i<=pos-1;i++)
		ptr=ptr->next;
		node *del=ptr->next;
		ptr->next=del->next;
		delete del;
		return;
	}
	else cout<<"OUT of"<<endl;
}

//Tim node
bool Find(int value)
{
	bool flag;
	node *p=last->next;
	while(p!=last)
	{
		if(p->data == value) flag = true;
		p=p->next;
	}
	if (flag) return true;
			return false;
}

void Display()
{
	node *p=last->next;
	while(p!=last)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<p->data<<endl;
}

main()
{
	for(int i=1;i<=5;i++)
	InsertLast(i);
	
	Display();
	
	int value,pos;
	cout<<endl<<"Nhap gia tri can them:";
	cin>>value;
	cout<<"Nhap vi tri can them:";
	cin>>pos;
	InsertPos(value,pos);
	
	Display();
	
	int posDel;
	cout<<"Nhap vi tri can xoa:";
	cin>>posDel;
	DeletePos(posDel);
	
	Display();
	
	if(Find(100)) cout<<"Tim thay "<<100<<endl;
		else cout<<"Khong tim thay "<<100<<endl;
}
