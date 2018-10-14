
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

//Doi sang cay phan chieu
void Mirror(node *T)
{
	if(T == NULL) return;
	else
	{
		node *tmp;
		Mirror(T->left);
		Mirror(T->right);
		tmp=T->left;
		T->left=T->right;
		T->right=tmp;
	}
}

//Xac dinh Cay nhi phan giong nhau
int CayGiongNhau(node *T1,node *T2)
{
	if(T1 == NULL && T2 == NULL) return 1;
	if(T1 != NULL && T2 != NULL)
	{
		return (T1->data == T2->data && CayGiongNhau(T1->left,T2->left) && CayGiongNhau(T1->right,T2->right));
	}
	return 0;
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

	node *T2=CreateNode(40);
	AddNode(T2,30);
	AddNode(T2,60);

	cout<<endl<<"Duyet theo thu tu truoc dung de quy:";
	NodeLeftRight(T);
	
	cout<<endl<<"Cay phan chieu la:";
	Mirror(T);
	NodeLeftRight(T);
	
	if(CayGiongNhau(T,T2) != 0 ) cout<<endl<<"hai cay giong nhau"<<endl;
		else cout<<endl<<"Hai cay khong giong nhau";
}

