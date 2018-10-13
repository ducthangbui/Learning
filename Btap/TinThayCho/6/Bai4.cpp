#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct SinhVien
{
	char ten[25];
	float toan,ly,tb;
};
typedef struct node
{
	SinhVien Data;
	node* next;
};
node* TaoNut(SinhVien x)
{
	node* n;
	n=(node*)malloc(sizeof(node));
	n->Data=x;
	n->next=NULL;
	return n;
}
void AddFirstNode(node* &head,node* n)
{
	if(head==NULL)
	{
		head=n;
		return;
	}
	n->next=head;
	head=n;
}
void TinhDiem(node* &head)
{
	if(head==NULL) 
	{
		printf("K co hoc sinh nao\n");
		return;
	}
	node* p=head;
	while(p!=NULL)
	{
		p->Data.tb=(p->Data.toan+p->Data.ly)/2;
		p=p->next;
	}
}
void Xuat(node* &head)
{
	if(head==NULL)
	{
		printf("Khong co sinh vien nao\n");
		return;
	}
	node* p=head;
	printf("Ten\tLy\tToan\tDiemTB\n");
	while(p!=NULL)
	{

		printf("%s\t%.2f\t%.2f\t%.2f\n",p->Data.ten,p->Data.ly,p->Data.toan,p->Data.tb);
		p=p->next;
	}
}
main()
{
	SinhVien x;
	node* p;
	node* head=NULL;
	int n,i=0;
	float toan,ly;
	char ten[25];
	printf("Nhap so sinh vien:");
	scanf("%d",&n);
	do
	{
		printf("Nhap ten:");
		fflush(stdin);
		gets(x.ten);
		printf("Nhap diem toan:");
		if(strlen(x.ten)>0)
		{
			scanf("%f",&toan);
			x.toan=toan;
			printf("Nhap diem ly:");
			scanf("%f",&ly);
			x.ly=ly;
		}
			p=TaoNut(x);
		AddFirstNode(head,p);
		i++;
	}while(i<n);
	printf("Danh sach khi chua co diem trung binh la:\n");
	Xuat(head);
	printf("\n============================================\n");
	printf("Danh sach sau khi da co diem trung binh la:\n");
	TinhDiem(head);
	Xuat(head);
	
}
