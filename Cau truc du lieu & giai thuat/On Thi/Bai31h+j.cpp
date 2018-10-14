/*Tree*/
#include <iostream>
#include <stack>
using namespace std;

struct node {
	int data;
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

//Kiem tra rong
bool Empty(node *T)
{
	if(T == NULL)
		return true;
			return false;
}

//Dem la
int CountLeaf(node *T)
{
	if(T == NULL)
	{
		return 0;//cay rong thi la = 0
	}
	else if(T->right == NULL && T->left == NULL)
		{
			return 1;//chi co 1 node thi so la = 1
		}
		else return(CountLeaf(T->left) + CountLeaf(T->right));
}

//Tim do cao cua cay
int DepthTree(node *T)
{
	if(T == NULL)
		return 0;//neu cay rong thi do cao cua cay = 1
	else
	{
		int leftDepth = DepthTree(T->left)+1;
		int rightDepth = DepthTree(T->right)+1;
		if(leftDepth > rightDepth)
			return leftDepth;
			else return rightDepth;
	}
}

//Xac dinh kich co cua 1 cay
int Size(node *T)
{
	if(T == NULL) return 0;
	else return (Size(T->left)+1+Size(T->right));
}

//Dem so la va in
int CountAndPrintLeaf(node *T)
{
		//In la
	//if(T->left == NULL || T->right == NULL) cout<<endl<<"La:"<<T->data<<" ";
	//Dem la
	if(T == NULL) return 0;
	else if(T->left == NULL && T->right == NULL) 
	{
		cout<<endl<<"La:"<<T->data;
		return 1;
	}
	else (CountAndPrintLeaf(T->left)+CountAndPrintLeaf(T->right));
	
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
			NodeLeftRight(T);
			break;
		}
	}
}

	cout<<endl<<"Size:"<<Size(T)
		<<endl<<CountAndPrintLeaf(T)
		<<endl<<"Do cao cua cay:"<<DepthTree(T)
		<<endl<<"So la:"<<CountLeaf(T);
		
}

