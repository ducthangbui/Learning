#include <conio.h>
#include <iostream>

using namespace std;

typedef struct tagAVLNode
{
	char bal;//chi so can bang
	int key;
	struct tagAVLNode* pLeft;
	struct tagAVLNode* pRight;
}AVLNode;
typedef AVLNode *AVLTree;

#define LH -1//cay con trai cao hon
#define EH 0 //2 cay con bang nhau
#define RH 1//cay con phai cao hon

void rotateLL(AVLTree &T);//quay don left-left
void rotateRR(AVLTree &T);//quay don right-right
AVLNode* createNode(int data);
int balanceLeft(AVLTree &T);//can bang khi cay lech ve ben trai
int balanceRight(AVLTree &T);//can bang khi cay lech ve ben phai
int insertNode(AVLTree &T, int x);
void duyet(AVLTree T);
void rotateLR(AVLTree &T);//quay kep left-right
void rotateRL(AVLTree &T);//quay kep right-left
int height(AVLTree T);//tinh chieu cao cua cay

int main()
{
	AVLTree T;
	T = NULL;
	int data;
	do
	{
		cout<<"moi ban nhap du lieu cho cay AVL(nhap -1 de ket thuc): ";
		cin>>data;
		if(data==-1) break;
		insertNode(T,data);
	}while(data!=-1);
	cout<<"cay AVL vua nhap: "<<endl;
	duyet(T);
	cout<<"chieu cao cua cay AVL vua nhap: "<<height(T);
	getch();
	return 0;
}

void rotateLL(AVLTree &T)
{
	AVLNode* T1 = T->pLeft;
	T->pLeft = T1->pRight;
	switch(T1->bal)
	{
	case LH: T->bal = EH;
		T1->bal = EH;break;
	case EH: T->bal = LH;
		T1->bal = RH;break;
	}
	T = T1;
}

void rotateRR(AVLTree &T)
{
	AVLNode* T1 = T->pRight;
	T->pRight=T1->pLeft;
	switch(T1->bal)
	{
	case RH:T->bal = EH;
		T1->bal = EH;break;
	case EH:T->bal=RH;
		T1->bal = LH;break;
	}
	T=T1;
}

AVLNode* createNode(int data)
{
	AVLNode* p;
	p = new AVLNode;
	if(p==NULL) return NULL;
	p->key=data;
	p->pLeft=NULL;
	p->pRight=NULL;
	p->bal=0;
	return p;
}

int balanceLeft(AVLTree &T)
{
	AVLNode* T1 = T->pLeft;
	switch(T1->bal)
	{
	case LH:rotateLL(T);return 2;
	case EH:rotateLL(T);return 1;
	case RH:rotateLR(T);return 2;
	}
	return 0;
}

int balanceRight(AVLTree &T)
{
	AVLNode* T1 = T->pRight;
	switch(T1->bal)
	{
	case LH:rotateRL(T);return 2;
	case EH:rotateRR(T);return 1;
	case RH:rotateRR(T);return 2;
	}
	return 0;
}

int insertNode(AVLTree &T, int x)
{
	int res;
	if(T)
	{
		if(T->key==x) return 0;
		if(T->key>x)
		{
			res = insertNode(T->pLeft,x);
			if(res<2) return res;
			switch(T->bal)
			{
			case RH:T->bal=EH;
				return 1;
			case EH:T->bal=LH;
				return 2;
			case LH:balanceLeft(T);
				return 1;
			}
		}
		else 
		{
			res = insertNode(T->pRight,x);
			if(res<2) return res;
			switch(T->bal)
			{
			case LH:T->bal=EH;
				return 1;
			case EH:T->bal=RH;
				return 2;
			case RH:balanceRight(T);return 1;
			}
		}
	}
	T = new AVLNode;
	if(T==NULL) return -1;
	T->key=x;
	T->bal=EH;
	T->pLeft=T->pRight=NULL;
	return 2;
}

void duyet(AVLTree T)
{
	if(T!=NULL)
	{
		duyet(T->pLeft);
		cout<<"khoa: "<<T->key<<" can bang: "<<T->bal<<endl;
		duyet(T->pRight);
	}
}

void rotateLR(AVLTree &T)
{
	AVLNode* T1 = T->pLeft;
	AVLNode* T2 = T1->pRight;
	T->pLeft = T2->pRight;
	T2->pRight = T;
	T1->pRight = T2->pLeft;
	T2->pLeft = T1;
	switch(T2->bal)
	{
	case LH: T->bal = RH;
		T1->bal = EH;break;
	case EH:T->bal = EH;
		T1->bal = EH;break;
	case RH:T->bal = EH;
		T1->bal = LH;break;
	}
	T2->bal = EH;
	T= T2;
}

void rotateRL(AVLTree &T)
{
	AVLNode* T1 = T->pRight;
	AVLNode* T2 = T1->pLeft;
	T->pRight = T2->pLeft;
	T1->pLeft = T2->pRight;
	T2->pRight = T1;
	switch(T2->bal)
	{
	case RH:T->bal = LH;
		T1->bal = EH;break;
	case EH:T->bal = EH;
		T1->bal = EH;break;
	case LH:T->bal = EH;
		T1->bal = RH;break;
	}
	T2->bal = EH;
	T = T2;
}

int height(AVLTree T)
{
	if(T==NULL) return -1;
	int HL=height(T->pLeft);
	int HR=height(T->pRight);
	return ((HL>HR)?HL:HR)+1;
}
