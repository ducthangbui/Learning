#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
Node *TaoNode(int x)
{
	Node *NodeMoi;
	NodeMoi= new Node;
	NodeMoi->data=x;
	NodeMoi->next=NULL;
	return NodeMoi;
}
Node *TimNodeCuoi(Node *head)
{
	Node *p=head;//node p nhu la node tam tro den dau danh sach
	if(p==NULL) return NULL;//neu p== NUll thi la danh sach rong
	while(p->next!=NULL)
	{
		p=p->next;//tro den node tiep theo
	}
	return p;//da tim duoc p la node cuoi cung
}
void ChenCuoi(Node *&head,Node *NodeChen)
{
	if(head==NULL) {
		head= NodeChen;//neu danh sach rong thi chi can chen n vao danh sach
		return;// roi ket thuc
	}
	Node *p=TimNodeCuoi(head);
	p->next=NodeChen;
}
void ChenDau(Node *&head,Node *NodeChen)
{
	if(head==NULL)
	{
		head=NodeChen;
		return;
	}
	NodeChen->next=head;
	head=NodeChen;
}
Node *TimNode(Node *&head,int GiaTriCanTim)
{
	Node *p=head;
	while(p!=NULL)
	{
		if(p->data==GiaTriCanTim) return p;
		p=p->next;
	}
	return NULL;//neu k co gia tri x thi tra ve NULL
}
void ChenViTriBatKi(Node *&head,Node *NodeCanChen,int GiaTriCanChen)
{
	Node *p=TimNode(head,GiaTriCanChen);
	if(p==NULL) return;//Neu k co x thi dung chuong trinh
	if(head->data==GiaTriCanChen)//Neu node can chen la node dau tien
	{
		ChenDau(head,NodeCanChen);
		return;
	}
	NodeCanChen->next=p->next;
	p->next=NodeCanChen;
}
//Tim Node dung truoc khoa = x
Node *TimNodeDungTruoc(Node *head,int x)
{
	Node *p=head;
	while(p->next!=NULL)
	{
		if(p->next->data==x) return p; 
	}
	return NULL;//Neu k tim thay thi tra ve NULL
}
//Xoa Node dau tien
void XoaNodeDauTien(Node *&head)
{
	Node *p=head;
	if(p==NULL) return;//
	head=head->next;
	delete p;
}
//Xoa node co khoa =x
void XoaNode(Node *&head,int x)
{
	if(head->data==x)
	{
		XoaNodeDauTien(head);
		return;
	}
	Node *p=TimNodeDungTruoc(head,x);//p la node dung truoc node can xoa
	if(p==NULL) return;
	Node *t=p->next;//t la node can xoa
	p->next=t->next;
	delete t;
}
void Xuat(Node *head)
{
	Node *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
}
main()
{
	Node *head=NULL;//khoi tri cho dau danh sach tro ve NULL vi chua biet no tro ve dau
	//cout<<"head ban dau:"<<head;
	Node *n1=TaoNode(1);
	Node *n2=TaoNode(2);
	Node *n3=TaoNode(3);
	Node *n4=TaoNode(4);
	Node *n5=TaoNode(5);
	ChenCuoi(head,n1);
	ChenCuoi(head,n2);
	ChenCuoi(head,n3);
	ChenDau(head,n4);
	ChenViTriBatKi(head,n5,2);
	cout<<"Danh sach vua nhap la:"<<endl;
	Xuat(head);
	cout<<endl<<"Danh sach sau khi xoa la:"<<endl;
	XoaNode(head,1);
	//Node *n5=TimNode(head,3);
	//if(n5!=NULL) cout<<"Tim duoc!!!"<<n5->data<<endl; else cout<<"Khong tim duoc!!!"<<endl;
	//cout<<endl<<"head sau:"<<head;
	Xuat(head);
}
