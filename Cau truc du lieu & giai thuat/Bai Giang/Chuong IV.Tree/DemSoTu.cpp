/*Cay nhi phan tim kiem*/
#include <iostream>
#include <string.h>
using namespace std;

struct node {
	char *data;
	int count;
	node *left,*right;
};

node *CreateNode(char *value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->count=1;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}

//Them node vao cay nhi phan tim kiem
void AddNode(node *T,char *value)
{
		node *p,*q;
		p=q=T;
		while(p->data != value && q != NULL)
		{
			p=q;
			if(strcmp(value,p->data)<0) 
			{
				q=p->left;
			}
			else 
			{
				q=p->right;
			}
		}
		
		if(strcmp(p->data,value) == 0) 
		{
			p->count=p->count+1;
			return;
		}
		node *newNode=CreateNode(value);
		if(strcmp(value,p->data)<0) p->left=newNode;
			else p->right=newNode;
}


//Duyet cay theo thu tu truoc
void NodeLeftRight(node *T)
{
	if(T != NULL)
	{
		cout<<T->data<<" ";
		cout<<T->count<<" ";
		NodeLeftRight(T->left);
		NodeLeftRight(T->right);
	}
}

main()
{
	node *T=CreateNode("AB");
	AddNode(T,"AC");
	AddNode(T,"AD");
	AddNode(T,"AE");
	AddNode(T,"AF");
	
	AddNode(T,"AB");
	AddNode(T,"AC");
	AddNode(T,"AD");
	AddNode(T,"AE");
	AddNode(T,"AF");
	
	AddNode(T,"AB");
	AddNode(T,"AC");
	AddNode(T,"AD");
	AddNode(T,"AE");

	
	NodeLeftRight(T);
}
