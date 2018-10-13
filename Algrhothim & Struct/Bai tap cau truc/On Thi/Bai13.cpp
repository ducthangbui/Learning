#include<iostream>
#define MAX 50
#define TRUE 1
#define FALSE 0
using namespace std;
struct pqueue{
	int rear;
	int nodes[MAX];
};
void pqinitialize(pqueue *ppq){
	ppq->rear=-1;
}
int pqempty(pqueue *ppq){
	return ((ppq->rear==-1)?TRUE:FALSE);
}
int pqueuesize(pqueue *ppq){
	return (ppq->rear+1);
}
void pqinsert(pqueue *ppq,int x){
	int i,j;
	if(ppq->rear==MAX-1);
	cout<<"\n hang doi bi day, khong them node duoc"<<endl;
	else{
		for(i=0;i<pqueuesize(ppq)&&ppq->nodes[i]>=x;i++)
			for(j=pqueuesize(ppq);j>i;j--)
				ppq->nodes[j]=ppq->nodes[j-1];
				ppq->nodes[i]=x;
				ppq->rear++;
	}
}
int pqremove(pqueue *ppq){
	int x,i;
	if(pqempty(ppq)){
		cout<<"\n hang doi bi rong, khong xoa node duoc"<<endl;
	}
	else{
		x=ppq->nodes[0];
		for(i=0;i<ppq->rear;i++)
			ppq->nodes[i]=ppq->nodes[i+1];
			ppq->rear--;
		return x;
	}
}
void pqtravarse(pqueue *ppq){
	int i;
	if(pqempty(ppq)){
		cout<<"\n hang doi bi rong"<<endl;
	}
	else{
		for(i=0;i<=ppq->rear;i++)
			cout<<ppq->nodes[i]<<"  ";
	}
}
int main(){
	pqueue *pq;
	int douutien,chucnang;
	do{
		system("cls");
		cout<<"\a\n\t\t***********WELCOME TO RUSSIA************\t\t"<<endl;
	}while(chucnang!=0);
	system("pause");
	return 0;
}
