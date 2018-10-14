#include<iostream>
using namespace std;
struct Queu
{
	int data;
	Queu *next;
};
Queu *TaoQueu(int x)
{
	Queu *QueuMoi;
	QueuMoi=new Queu;
	QueuMoi->data=x;
	QueuMoi->next=NULL;
	return QueuMoi;
}
Queu *TimNodeCuoi(Queu *head)
{
	Queu *p=head;//node p nhu la node tam tro den dau danh sach
	if(p==NULL) return NULL;//neu p== NUll thi la danh sach rong
	while(p->next!=NULL)
	{
		p=p->next;//tro den node tiep theo
	}
	return p;//da tim duoc p la node cuoi cung
}
void push(Queu *&head,int x)
{
	Queu *QueuThem=TaoQueu(x);
	
	if(head==NULL) {
		head= QueuThem;//neu danh sach rong thi chi can chen n vao danh sach
		return;// roi ket thuc
	}
	Queu *p=TimNodeCuoi(head);
	p->next=QueuThem;
}
void pop(Queu *&head,int x)//pop x phan tu cua Queu
{
	int dem=1;
	while(dem<=x)
	{
	Queu *p=head;
	if(p==NULL) return;//
	head=head->next;
	delete p;
	dem++;
	}
}
void Xuat(Queu *head)
{
	Queu *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
}
main()
{
	Queu *head=NULL;
	push(head,1);
	push(head,2);
	push(head,3);
	Xuat(head);
	int x=2;
	cout<<endl<<"Lay ? phan tu cua Queu?"<<endl;
	cout<<"ban chon:";
	//cin>>x;
	cout<<endl<<"Queu sau khi pop "<<x<<" phan tu la:"<<endl;
	pop(head,x);
	Xuat(head);
}
