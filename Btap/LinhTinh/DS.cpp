#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Sv
{
	char ten[30];
	float diem;
};
typedef struct node
{
	Sv key;
	node* next;
}node;
node* CreateNode(Sv x)
{
	node* n;
	n=(node*)malloc(sizeof(node));
	n->key=x;
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
node* FindEndNode(node* head)
{
	node* p=head;
	if(p==NULL) return NULL;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	return p;
}
void AddLastNode(node* &head,node* n)
{
	if(head==NULL)
	{
		head=n;
		return;
	}
	node* p=FindEndNode(head);
	p->next=n;
}
void XuatDS(node* &head)
{
	node* p=head;
	printf("Ho&ten\tDiem\n\n");
	while(p!=NULL)
	{
		printf("%s\t%.2f\n",p->key.ten,p->key.diem);
		p=p->next;
	}
}
void NhapDuLieuTuFile(node* &head,Sv &Sv)
{
FILE *f;
f = fopen("DS.txt", "r");

if (f == NULL)
{
printf("Khong doc duoc file\n");
fclose(f);
return;
}

while (!feof(f))
{
fgets(Sv.ten,100,f);
//fflush(stdin);
Sv.ten[strlen(Sv.ten)-1] ='\0';
fscanf(f,"%f",&Sv.diem);
node *p= CreateNode(Sv);
//AddTail(l, pNode);
AddLastNode(head,p);
}
}
main()
{
	node* head=NULL;
	node* p;
	char ten[30];
	Sv s;
	NhapDuLieuTuFile(head,s);
	XuatDS(head);
}
