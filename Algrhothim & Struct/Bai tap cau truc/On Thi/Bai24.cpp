/*Cay nhi phan tim kiem*/
#include <iostream>
#include <stack>
using namespace std;

struct node {
	bool no;
	int data;
	node *left,*right;
};

node *CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}

//Duyet cay theo thu tu truoc
void NodeLeftRight(node *T)
{
	if(T != NULL)
	{
		cout<<T->data<<" ";
		NodeLeftRight(T->left);
		NodeLeftRight(T->right);
	}
}

//Duyet cay theo thu tu giua
void LeftNodeRight(node *T)
{
	if(T!=NULL)
	{
		LeftNodeRight(T->left);
		cout<<T->data<<" ";
		LeftNodeRight(T->right);
	}
}

//Duyet cay theo thu tu sau
void LeftRightNode(node *T)
{
	if(T!=NULL)
	{
		LeftRightNode(T->left);
		LeftRightNode(T->right);
		cout<<T->data<<" ";
	}
}

//Them node vao cay nhi phan tim kiem
void AddNode(node *T,int value)
{
		node *p,*q;
		p=q=T;
		while(p->data != value && q != NULL)
		{
			p=q;
			if(value < p->data) q=p->left;
			else q=p->right;
		}
		if(p->data == value) return;
		node *newNode=CreateNode(value);
		if(value < p->data) p->left=newNode;
			else p->right=newNode;
}

//Tim kiem
bool Search(node *T,int value)
{
	node *p=T;
	bool flag;
	if(p!=NULL)
	{
		if(value == p->data) flag=true;
		else if(value < p->data) p=p->left;
			else p=p->right;
	}
	return flag;
}

//Tim phan tu the mang
void TimPhanTuTheMang(node *&p,node *&q)// p the mang cho q
{
	if(q->left != NULL)
	{
		TimPhanTuTheMang(p,q->left);
	}
	else//Da tim ra trai nhat
	{
		p->data=q->data;
		p=q;
		q=q->right;
	}
}
//Xoa node trong cay tim kiem nhi phan
void Delete(node *&T,int x)
{
	if(T == NULL)
	{
		return;
	}
	//===Xoa node 1 con va cac node la ===
	if(x < T->data)
	{
		Delete(T->left,x);
	}
	else if(x > T->data)
	{
		Delete(T->right,x);
	}
	else
	{
		node *p = T;
		if(T->left == NULL)	T=T->right;
		else if(T->right == NULL) T=T->left;
		//===============================
		
		//Xoa node co 2 con
		else
		{
			//Cach 1:Trai nhat cua cay con phai
			TimPhanTuTheMang(p,T->right);
		}
		delete p;
	}
	
	
}

//Xoay trai
void RotateLeft(node *T)
{
	node *p=T;//p tro den node goc 
	if(T == NULL)
	{
		cout<<endl<<"Cay rong"<<endl;
	}
	else if(T->right == NULL) cout<<endl<<"Khong co cay con phai"<<endl;
	else{
		p=T->right;
		T->right=p->left;
		p->left=T;
	}	
}

//Xoay phai


void makeNo(node *p)
{
	p->no=true;
	if(p->left != NULL) makeNo(p->left);
	if(p->right != NULL) makeNo(p->right);
}
//Duyet truoc khong dung de quy
void NLR(node *T)
{
	stack <node*> a;
	a.push(T);
	cout<<T->data<<" ";
	T->no=false;
	while(!a.empty())
	{
		node *t=a.top();
		if(t->left != NULL && t->left->no == true)
		{
			cout<<t->left->data<<" ";
			t->left->no=false;
			a.push(t->left);
		}
		else if(t->right != NULL && t->right->no == true)
		{
			cout<<t->right->data<<" ";
			t->right->no=false;
			a.push(t->right);
		}
		else a.pop();
	}
	cout<<endl;
	makeNo(T);
}

//Duyet giua khong dung de quy
void LNR(node *T)
{
	stack <node*> a;
	a.push(T);
	while(!a.empty())
	{
		node *t=a.top();
		if(t->left != NULL && t->left->no == true) a.push(t->left);
		else
		{
			if(t->no == true)
			{
				cout<<t->data<<" ";
				t->no=false;
			}
			if(t->right != NULL && t->right->no == true) a.push(t->right);
			else a.pop();
		}
	}
	cout<<endl;
	makeNo(T);
}

//DUyet cay theo thu tu cuoi khong dung de quy
void LRN(node *T)
{
	stack <node*> a;
	a.push(T);
	while(!a.empty())
	{
		node *t=a.top();
		if(t->left != NULL && t->left->no == true) a.push(t->left);
		else if(t->right != NULL && t->right->no == true) a.push(t->right);
		else{
			cout<<T->data<<" ";
			t->no=false;
			a.pop();
		}
	}
	cout<<endl;
	makeNo(T);
}
main()
{
	node *T=CreateNode(40);
	AddNode(T,30);
	AddNode(T,60);
	AddNode(T,25);
	AddNode(T,35);
	AddNode(T,50);
	AddNode(T,70);
	cout<<endl<<"Duyet theo thu tu truoc khong dung de quy:";
	NLR(T);
//	cout<<"Do cao cua cay:"<<High(1);	
//	cout<<endl<<"Sau khi xoa:";
//	Delete(T,10);
	cout<<endl<<"Duyet theo thu tu truoc dung de quy:";
	NodeLeftRight(T);
	
	int del;
	cout<<endl<<"Nhap gia tri can xoa:";
	cin>>del;
	Delete(T,del);
	cout<<endl<<"Cay sau khi xoa:";
	NLR(T);
	
	cout<<endl<<"Cay sau khi xoay trai la:";
	RotateLeft(T);
	NodeLeftRight(T);
}




