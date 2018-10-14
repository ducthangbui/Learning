#include<iostream>
#include<windows.h>
#define MAX 5
using namespace std;
string THONGBAO[3]={"OK!\n","FULL!!!\n","EMPTY!!!\n"};
/*Ngan xep (stack) su dung mang*/
struct stack_m{
	int mang[MAX];
	int id_top=0;
};

//Kiem tra trang thai stack 2=Emty, 1=Full, 0=Available
int checkstack_m(stack_m *s){
	if (s->id_top==0) return 2;
	if (s->id_top==MAX) return 1;
	return 0;
}

//Push phan tu x vao stack, tra ve trang thai cua stack sau khi push
int pushstack_m(stack_m *s, int x){
	if (checkstack_m(s)!=1){
		s->mang[s->id_top]=x;
		s->id_top++;
	}
	return checkstack_m(s);
}

//Pop top cua stack luu vao x, tra ve trang thai cua stack sau khi pop
int popstack_m(stack_m *s, int &x){
	if (checkstack_m(s)!=2) {
		x=s->mang[--s->id_top];
	}
	return checkstack_m(s);
}
/*Ket thuc phan ngan xep mang*/

/*Hang cho (queue) su dung mang*/
struct queue_m{
	int mang[MAX];
	int id_top=0;
	int id_bot=0;
	//int count=0;
};

//Kiem tra trang thai cua queue, gia tri tra ve tuong tu stack
int checkqueue_m(queue_m *q){
	if (q->id_top==MAX) q->id_top=-1;
	if(q->id_bot!=0&&q->id_top==-1) q->id_top=0; 
	if (q->id_bot==MAX) q->id_bot=0;
	if (q->id_bot==q->id_top+1) {
		return 1;
	}
	if (q->id_bot==q->id_top) {
		return 2;
	}
	return 0;
}

//Push phan tu x vao queue, tra ve trang thai cua queue sau khi push
int pushqueue_m(queue_m *q, int x){
	if (checkqueue_m(q)!=1) {
		q->mang[q->id_top]=x;
		q->id_top++;
		//q->count++;
	}
	return checkqueue_m(q);
}

//Pop phan tu dau tien cua queue luu vao x, tra ve trang thai cua queue sau khi pop
int popqueue_m(queue_m *q, int &x){
	if (checkqueue_m(q)!=2) {
		x=q->mang[q->id_bot];
		q->id_bot++;
		//q->count--;
	}
	return checkqueue_m(q);
}
/*Ket thuc phan hang cho mang*/

/*Ngan xep su dung con tro*/
struct stack_p{
	int value;
	stack_p *next=NULL;
};

//Push 
stack_p *pushstack_p(stack_p *s, int x){
	stack_p *tmp=new stack_p;
	tmp->value=x;
	tmp->next=s;
	return tmp;
}

//Pop
stack_p *popstack_p(stack_p *s, int &x){
	if (s==NULL) {
		cout<<THONGBAO[2];
		return s;
	}
	x=s->value;
	stack_p *tmp=new stack_p;
	tmp=s->next;
	delete s;
	return tmp;
}
/*Ket thuc ngan xep su dung con tro*/

/*Hang doi su dung con tro*/
struct node{
	int value;
	node *next=NULL;
};
struct queue_p{
	node *front=NULL;
	node *rear=NULL;
	//int count=0;
};

//Push
queue_p *pushqueue_p(queue_p *q, int x){
	node *n = new node;
	n->value=x;
	n->next=NULL;
	if (q!=NULL){
		q->rear->next=n;
		q->rear=n;
	}
	else{
		q=new queue_p;
		q->rear=n;
		q->front=n;
	}
	return q;
	//q->count++;
}

//Pop
queue_p *popqueue_p(queue_p *q, int &x){
	if (q!=NULL){
		node *tmp=new node;
		tmp=q->front;
		x=q->front->value;
		q->front=q->front->next;
		delete tmp;
		if (q->front==NULL) q=NULL;
	}
	return q;
}
/*Ket thuc hang doi su dung con tro*/

/*HAM TEST*/
//Test stack mang
void TestStack_m(){
	stack_m *s=new stack_m;
	int x;
	int i=0;
	int c=1;
	while (c!=0){
		system("cls");
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>c;
		if (c==1){
			do{
				cout<<"x= ";
				cin>>x;
				cout<<THONGBAO[pushstack_m(s,x)];
				cout<<"1. Tiep tuc		0. Thoi"<<endl;
				cin>>x;
			} while (x!=0);
		}
		if (c==2){
			do{
				i=checkstack_m(s);
				if (i!=2){
					popstack_m(s,x);
					cout<<"x= "<<x<<endl;
				}
				else cout<<THONGBAO[i];
				cout<<"1. Tiep tuc		0. Thoi"<<endl;
				cin>>x;
			} while (x!=0);
		}
	}
}

//Test queue mang	
void TestQueue_m(){
	queue_m *q=NULL;
	int x;
	int i=0;
	int c=1;
	while (c!=0){
		system("cls");
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>c;
		if (c==1){
			do{
				cout<<"x= ";
				cin>>x;
				cout<<THONGBAO[pushqueue_m(q,x)];
				cout<<"1. Tiep tuc		0. Thoi"<<endl;
				cin>>x;
			} while (x!=0);
		}
		if (c==2){
			do{
				i=checkqueue_m(q);
				if (i!=2){
					popqueue_m(q,x);
					cout<<"x= "<<x<<endl;
				}
				else cout<<THONGBAO[i];
				cout<<"1. Tiep tuc		0. Thoi"<<endl;
				cin>>x;
			} while (x!=0);
		}
	}
}

//Test stack con tro
void TestStack_p(){
	stack_p *s=NULL;
	int x;
	int i=0;
	int c=1;
	while (c!=0){
		system("cls");
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>c;
		if (c==1){
			do{
				cout<<"x= ";
				cin>>x;
				s=pushstack_p(s,x);
				cout<<THONGBAO[0];
				cout<<"1. Tiep tuc		0. Thoi"<<endl;
				cin>>x;
			} while (x!=0);
		}
		if (c==2){
			do{
				if (s==NULL) cout<<THONGBAO[2];
				else {
					s=popstack_p(s,x);
					cout<<"x= "<<x<<endl;
				}
				cout<<"1. Tiep tuc		0. Thoi"<<endl;
				cin>>x;
			} while (x!=0);
		}
	}
}

//Test queue con tro
void TestQueue_p(){
	queue_p *q=NULL;
	int x;
	int i=0;
	int c=1;
	while (c!=0){
		system("cls");
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>c;
		if (c==1){
			cout<<"x= ";
			cin>>x;
			q=pushqueue_p(q,x);
			system("pause");
		}
		if (c==2){
			if (q==NULL) cout<<THONGBAO[2];
			else {
				q=popqueue_p(q,x);
				cout<<"x= "<<x<<endl;
			}
			system("pause");
		}
	}
}

/*MENU*/
void menu(){
	int m;
	do{
		system("cls");
		cout<<"1. Test Stack Mang"<<endl;
		cout<<"2. Test Queue Mang"<<endl;
		cout<<"3. Test Stack Contro"<<endl;
		cout<<"4. Test Queue Contro"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>m;
		switch (m){
			case 1:{
				TestStack_m();
				break;
			}
			case 2:{
				TestQueue_m();
				break;
			}
			case 3:{
				TestStack_p();
				break;
			}
			case 4:{
				TestQueue_p();
				break;
			}
		}
	} while (m!=0);
}

/*MAIN*/
int main(){
	menu();
	return 0;
}
