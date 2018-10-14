#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

node *CreatNode(int value)//Tao node
{
	node *tmp;//tao node tmp
	tmp = new node;//cap phat bo nho cho tmp
	if(tmp==NULL)//Neu khong du khong gian bo nho
	{
		cout<<"Khong du bo nho de cap phat"<<endl;
		return 0;
	}
	else
	{
		tmp->data=value;//thiet lap gia tri cho node tmp
		tmp->next=NULL;//thiet lap lien ket cho node tmp
		return tmp;//tra ve node tmp da duoc thiet lap
	}
	
}
void InsertPos(node *&start)//Thêm node va`o vi? tri´ pos
{
	int value;//gia´ tri? che`n va`o ds
	int pos;//vi? tri´ che`n
	int counter = 0;//biê´n dê´m
	cout << "Nhap gia tri node";
	cin >> value;
	cout << "Nhap vi tri chen node:";
	cin >> pos;
	node *tmp, *p, *ptr;
	tmp = CreatNode(value);//ta?o node tmp co´ gia´ tri?n la` value
	p = start;//p tro? dê´n node dâ`u tiên
	while (p != NULL)
	{
		p = p->next;
		counter++;//Ðê´m sô´ node cu?a ds
	}
	if (pos == 1)//Nê´u pos la` vi? tri´ dâ`u tiên
	{
		if (start == NULL)//Nê´u danh sa´ch rô~ng
		{
			start = tmp;//node câ`n thêm chi´nh la` node tmp
			start->next = NULL;//không liên kê´t vo´i node na`o nu~a
		}
		else
		{
			ptr = start;//ptr tro? dê´n node dâ`u tiên
			start = tmp;//ga´n node dâ`u tiên la` node tmp
			start->next = ptr;//không liên kê´t vo´i node na`o nu~a
		}
	}
	else//Nê´u không pha?i la` node dâ`u tiên
	if (pos > 1 && pos <= counter)//Truo`ng ho?p pos ho?p lê?
	{
		p = start;//p tro? dê´n node dâ`u tiên;
		for (int i = 1; i < pos; i++)
		{
			ptr = p;
			p->next = NULL;
		}
		ptr->next = tmp;
		tmp->next = p;//Thiê´t lâ?p liê´n kê´t cho node
	}
	else//Nê´u vi? tri´ pos k ho?p lê?
	{
		cout << "Vuot qua gioi han DSLK" << endl;
	}
}
void InsertBegin(node *&head)//Chen node vao dau DSLK
{
	int value;//gia tri can chen
	cout<<"Nhap gia gtri cua node:";
	cin>>value;
	node* tmp, *p;
	tmp=CreatNode(value);//Tao node tmp voi gia tri value
	if(head==NULL){//Neu ds rong
		head=tmp;//Ds chinh la node tmp
		tmp->next=NULL;//k co lien ket voi node khac
	}
	else//Neu danh sach khong rong
	{
		p=head;//p tro den node dau cua head
		head=tmp;//head dc tro den tmp
		head->next=p;//head tro den goc cu
	}
	cout<<"Hoan thanh them node vao dau dslk don"<<endl;
}

void DelNode(node *&head)//Xoa node
{
	int pos;//vi tri can xoa
	int i,counter=0;
	
	if(head==NULL)//neu danh sach rong 
	{
		cout<<"khong thuc hien dc"<<endl;
		return;
	}
	cout<<endl<<"Vi tri can xoa:";
	cin>>pos;
	node *s,*ptr;
	s=head;//node s tro den dau danh sach
	if(pos==1)
	{//Neu vi tri loai bo la node dau tien
		head=s->next;
		s->next=NULL;
		delete(s);
	}
	else
	{
		while(s!=NULL)
		{
			s=s->next;
			counter++;//Dem so node
		}
		if(pos>0&&counter<=counter)//Neu vi tri hop le
		{
			s=head;//s tro den node dau tien
			for(int i=1;i<pos;i++)
			{
				ptr=s;
				s=s->next;
			}
			ptr->next=s->next;//Thiet lap lien ket cho node
		}
		else
		{
			cout<<"Vi tri ngoai danh sach"<<endl;
		}
		delete(s);
		cout<<"Node da bi loai bo"<<endl;
	}
}

void Display(node *&head)//hien thi
{
	node *tmp;
	if(head==NULL)
	{
		cout<<"Khong co dslk de hien thi"<<endl;
		return;
	}
	
	tmp=head;//tmp tro den node dau tien trong dslk
	cout<<endl<<"Noi dung cua dslk"<<endl;
	while(tmp!=NULL)//Lap cho den node cuoi cung
	{
		cout<<tmp->data<<"->";//hien thi thanh phan thong tin
		tmp=tmp->next;//tro den node ke tiep
	}
}

int main()
{
	node *head=NULL;
	InsertBegin(head);
	InsertBegin(head);
	Display(head);
	//DelNode(head);
	//Display(head);
	InsertPos(head);
	Display(head);
	return 0;
}
