#include<iostream>
using namespace std;
struct Stack{
    int n;
    Stack *next;
};
//chen vao cuoi danh sach
Stack *push(Stack *a, int  x){
    Stack *temp;
    temp= new Stack;
    //truy cap vao phan tu cua con tro qua ->
    temp->next=NULL;
    //neu a =NULL hay danh sach khong co phan tu nao
    if(a==NULL) {
        return temp;
    }
        temp->n= x;
    temp->next= a;

    return  temp;
}
Stack *pop(Stack *a, int  &x){
    Stack *temp;
    //neu a =NULL hay danh sach khong co phan tu nao
    if(a==NULL) {
        cout<<"Stack rong"; x= 0;
        return NULL;
    }
    temp= a->next;
    x=a->n;
    delete a;
    return  temp;
}
void hienthi(Stack *a){
    Stack *temp;
    temp= a;
    if (temp==NULL) {cout<<"Stack rong";return;}
    do {
        cout<<temp->n<<"  ";
        temp= temp->next;
    }while(temp!=NULL);
    cout<<endl;
}

int main(){
    Stack *q =NULL;
    int x;
    q= push(q, 1);
    q=push(q, 2);
    q= push(q,3);
    hienthi(q);
    q= push(q, 4);
    hienthi(q);
    q= pop(q,x);
    cout<<"Stack sau khi pop "<<x<<" la: ";
    hienthi(q);
}
