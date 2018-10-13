/*Tree*/
#include <iostream>
#include <stack>
using namespace std;

struct node {
	int data;
	bool no;
	node *left,*right;
};

//node *tree=NULL;

//Tao node
node *CreateNode(int value)
{
	node *newNode = new node;
	newNode->data=value;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

//Duyet cay co 3 cach
//Duyet cay theo thu tu truoc
//

void NodeLeftRight(node *T)
{
	if(T!=NULL)
	{
		cout<<T->data<<" ";//in node goc
		NodeLeftRight(T->left);//duyet theo thu tu giua sang nhanh cay con ben trai
		NodeLeftRight(T->right);//duyet theo thu tu giau sang nhanh cay con ben phai
	}
}

//Duyet theo thu tu giua

void LeftNodeRight(node *T)
{
	if(T!=NULL)
	{
		LeftNodeRight(T->left);
		cout<<T->data<<" ";//in ra node goc
		LeftNodeRight(T->right);
	}
}

//Duyet theo thu tu sau

void LeftRightNode(node *T)
{
	if(T != NULL)
	{
		LeftRightNode(T->left);
		LeftRightNode(T->right);
		cout<<T->data<<" ";
	}
}

//Tim node p co noi dung x tren cay
node *Search(node *T,int x)
{
	node *tmp;
		if(T == NULL)
	{
		return NULL;
	}
	if(T->data == x) return T;//Neu node goc la node can tim thi tra ve node goc

	tmp=Search(T->left,x);//Tim o nhanh cay bven trai
	if(tmp == NULL)//Neu k thay o nhanh cay ben trai
		tmp=Search(T->right,x);//thi tim sang cay con ben phai
	return tmp;	
}


//Kiem tra rong
bool Empty(node *T)
{
	if(T == NULL)
		return true;
			return false;
}

//Them node la con ben trai sau node x voi gia tri y
void AddLeft(node *T,int x,int y)
{
	node *p,*q;
	p=Search(T,x);
	if(p == NULL)
	{
		cout<<"Khong co node goc"<<endl;
		return;
	}
	if(p->left != NULL)
	{
		cout<<endl<<"Khong them duoc";
		return;
	}
	else 
	{
		q=CreateNode(y);
		p->left=q;
	}
}
//Them node la con ben trai sau node x voi gia tri y
void AddRight(node *T,int x,int y)
{
	node *p,*q;
	p=Search(T,x);
	if(p == NULL)
	{
		cout<<"Khong co node goc"<<endl;
		return;
	}
	if(p->right != NULL)
	{
		cout<<endl<<"Khong them duoc";
		return;
	}
	else 
	{
		q=CreateNode(y);
		p->right=q;
	}
}

//Loai bo la ben trai node co noi dung x
void RemoveLeft(node *T,int x)
{
	node *p,*q;
	p=Search(T,x);
	if(p == NULL)
	{
		cout<<endl<<"Khong ton tai node co noi dung "<<x<<endl;
		return;
		
	}
	//neu p co nhanh cay con ben trai
	if(p->left == NULL)
	{
		cout<<endl<<"Khong the xoa node nay";
		return;
	}
	else 
	{
		q=p->left;//node la trai la q
		p->left=NULL;
		delete q;
	}
}

//Loai bo la ben phai node co noi dung x
void RemoveRight(node *T,int x)
{
	node *p=Search(T,x);
	if(p == NULL)
	{
		cout<<endl<<"Khong ton tai node can xoa:";
		return;
	}
	
	if(p->right == NULL)
	{
		cout<<endl<<"Khong the xoa";
		return;
	}
	else{
	node *q=p->right;
	p->right=NULL;
	delete q;
	}
}

void makeNo(node *p)
{
	p->no = true;

	if (p->left != NULL) makeNo(p->left);
	if (p->right != NULL) makeNo(p->right);
}

//Duyet cay theo thu tu truoc khong dung de quy
void NLR(node *T)
{
	stack<node*> a;

	a.push(T);
	T->no = false;

	cout << T->data << " ";

	while (!a.empty())
	{
		node *t;

		t = a.top();

		if (t->left != NULL&&t->left->no == true)
		{
			cout << t->left->data << " ";

			t->left->no = false;

			a.push(t->left);
		}
		else
		if (t->right != NULL&&t->right->no)
		{
			cout << t->right->data << " ";

			t->right->no = false;

			a.push(t->right);
		}
		else a.pop();
	}

	cout << endl;

	makeNo(T);
}

//Duyet theo thu tu giua khong dung de quy
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
			if(t->no==true)
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

//Duyet cay theo thu tu cuoi khong dung de quy
void LRN(node *T)
{
	stack <node*> a;
	a.push(T);
	while(!a.empty())
	{
		node *t=a.top();
		if(t->left != NULL && t->left->no == true) a.push(t->left);
		else
		if(t->right != NULL && t->right->no == true) a.push(t->right);
		else
		{
			cout<<t->data<<" ";
			t->no=false;
			a.pop();
		} 
	}
	cout<<endl;
	makeNo(T);
}
main()
{
	node *T,*T1;
	int value;
	int choice;
	cout<<"Nhap node goc:";
	cin>>value;
	T=CreateNode(value);
	int n;
//	cout<<"Nhap so node cua cay:";
//	cin>>n;
//	for(int i=1;i<=n;i++)
{	
m:	cout<<"1.Nhap node trai"
		<<endl<<"2.Nhap node phai"
		<<endl<<"3.Duyet NLR"<<endl;
	cout<<"Ban chon:";
	cin>>choice;
	switch(choice)
	{
		case 1:{
			int x,y;
			cout<<"Gia tri node can chen sau:";
			cin>>x;
			cout<<"Gia tri node moi:";
			cin>>y;
			AddLeft(T,x,y);
			goto m;
			break;
		}
		case 2:{
			int x,y;
			cout<<"Gia tri node can chen sau:";
			cin>>x;
			cout<<"Gia tri node moi:";
			cin>>y;
			AddRight(T,x,y);
			goto m;
			break;
		}
		case 3:{
			//NodeLeftRight(T);
			NLR(T);
			break;
		}
	}
}
	
	int del;
	cout<<endl<<"Nhap gia tri node can xoa trai:";
	cin>>del;
	RemoveLeft(T,del);
	
	cout<<endl<<"Cay sau khi xoa trai:";
	NodeLeftRight(T);		
	
	int del2;
	cout<<endl<<"Nhap gia tri node can xoa phai:";
	cin>>del2;
	RemoveRight(T,del2);
	cout<<endl<<"Cay sau khi xoa phai:";
	NodeLeftRight(T);
	

}

