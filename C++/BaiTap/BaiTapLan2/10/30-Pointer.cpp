#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

ofstream xuat("sinhvien-pointer.txt", ios::out);

struct SinhVien{
	string ten;
	float diem;
	string gioitinh;
};

struct Node{
	SinhVien svMoi;
	Node *next;
};

Node *TaoNode(SinhVien x)
{
	Node *NodeMoi = new Node;
	NodeMoi->svMoi = x;
	NodeMoi->next = NULL;
	return NodeMoi;
}

void ChenDau(Node *&head, Node *NodeChen)
{
	if (head == NULL ){
		head = NodeChen;
		return;
	}
	NodeChen->next = head;
	head = NodeChen;
}

Node *TimNode(Node *&head, string tencantim){
	Node *p = head;
	while (p != NULL){
		if(p->svMoi.ten == tencantim) return p;
		p = p->next;
	}
	return NULL;//tra ve NULL neu k tim duoc
}

Node *Sua(Node *&head, string tencantim, float diemcansua){
	Node *p = head;
	while (p != NULL ){
		if (p->svMoi.ten == tencantim){
			p->svMoi.diem = diemcansua;
			p= p->next;
		}
		return p;
	}
	return NULL;
}

void Xuat(Node *&head)
{
	Node *p = head;
	while (p != NULL){
		xuat <<"Ho ten:" << p->svMoi.ten << endl 
		     <<"Gioi tinh:" << p->svMoi.gioitinh << endl
		     <<"Diem:" << p->svMoi.diem << endl << endl;
		     p = p->next;
	}
}
//Tim Node dung truoc khoa = x
Node *TimNodeDungTruoc(Node *head,string tencantim)
{
	Node *p=head;
	while(p->next!=NULL)
	{
		if(p->next->svMoi.ten==tencantim) return p; 
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
void XoaNode(Node *&head,string tencantim)
{
	Node *q = head;
	if(q->svMoi.ten==tencantim)
	{
		XoaNodeDauTien(head);
		return;
	}
	Node *p=TimNodeDungTruoc(head,tencantim);//p la node dung truoc node can xoa
	if(p==NULL) return;
	Node *t=p->next;//t la node can xoa
	p->next=t->next;
	delete t;
}
void Nhap(Node *&head){
	Node *NodeMoi;
	int soSv, dem=0;
	SinhVien svMoi;
	cout<<"Nhap so sinh vien:";
	cin>>soSv;
	while ( soSv > dem)
	{
		getline(cin,svMoi.ten);
		cout<<"Nhap ten:";
		getline(cin,svMoi.ten);
		cout<<"Nhap gioi tinh:";
		cin>>svMoi.gioitinh;
		cout<<"Nhap diem:";
		cin>>svMoi.diem;
		NodeMoi = TaoNode(svMoi);
		ChenDau(head,NodeMoi);
		dem++;
	}
}

int main()
{
	Node *head=NULL;
	string tencantim, tencansua;
	float diemcansua;
	SinhVien svThem;
	
	Nhap(head);
	Xuat(head);
	//////////////////////
				 ////////////////////////////////////
	string tenxoa;
	getline(cin,tenxoa);
	cout<<"Nhap ten can xoa:";
	getline(cin,tenxoa);
	XoaNode(head,tenxoa);
	xuat<<"Danh sach sinh vien sau khi xoa "<<tenxoa<<" la:";
	Xuat(head);
	//////////////////////////////////
	//getline(cin,svThem.ten);
	xuat<<"Danh sach sau khi them:"<<endl;
	//getline(cin,svThem.ten);
	cout<<"Nhap ten can sinh vien can them:";
	getline(cin,svThem.ten);
	cout<<"Nhap gioi tinh sinh vien can them:";
	cin>>svThem.gioitinh;
	cout<<"Nhap diem sinh vien can them:";
	cin>>svThem.diem;
	Node *NodeThem = TaoNode(svThem);
	ChenDau(head,NodeThem);
	Xuat(head);
	/////////////////////////////

	xuat<<endl;
	getline(cin,tencantim);
	cout<<"Nhap ten can tim:";
	getline(cin,tencantim);
	Node *NodeTim = TimNode(head,tencantim);
	xuat<< endl <<"Ket qua tim theo "<<tencantim<<" la:"<<endl
	<<"Ho ten:"<<NodeTim->svMoi.ten
		<<endl<<"Gioi tinh:"<<NodeTim->svMoi.gioitinh
		 <<endl<<"Diem:"<<NodeTim->svMoi.diem<<endl;
		 ////////////////////////
		 //getline(cin,tencansua);
		 cout<<"Nhap ten can sua diem:";
		 getline(cin,tencansua);
		 cout<<"Nhap diem:";
		 cin>>diemcansua;
		 Node *SuaDiem = Sua(head,tencansua,diemcansua );
		 ChenDau(head,SuaDiem);
		 //Xuat(head);
		 xuat<< endl <<"Sinh vien "<<tencansua<<" sau khi sua diem la:"<<endl
	<<"Ho ten:"<<SuaDiem->svMoi.ten
		<<endl<<"Gioi tinh:"<<SuaDiem->svMoi.gioitinh
		 <<endl<<"Diem:"<<SuaDiem->svMoi.diem<<endl;

	return 1;
}
