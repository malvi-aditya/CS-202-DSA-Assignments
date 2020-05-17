#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;// pointer to next node
    // structure of one node
};
node *newnode(int value){
    node *p =new node;
    p->next = p;
    p->data = value;
    return p;
    // create a new node
}
void potato_problem(int n,int k){
    node *head= newnode(1);//first node will contain 1
    node *tail=head;//first initializing so tail points to head
    for(int i=2;i<=n;i++){
        tail->next = newnode(i);// 
		tail = tail->next;//now tail points to the new node 
    }
    tail->next=head;//circular linked list created
    node *m=head,*q=head;
    int a=0;
    //when m-next=m,only one node left in list(element pointing itself)
    while(m->next!=m){
        int b=1;
        while(b!=k){
            q=m;
            m=m->next;
            b++;
        }
        a=a+1;
        if(a==1){
             cout<<"["<<a<<"]"<<"At first,person at position "<<m->data<<" is removed\n";
        }
        else if(a==n-1){
            cout<<"["<<a<<"]"<<"Finally,person at position "<<m->data<<" is removed\n";
        }
        else{
            cout<<"["<<a<<"]"<<"Then person at position "<<m->data<<" is removed\n";
        }
        q->next=m->next;
        m=q->next;
    }
    cout<<"Therefore,person at position "<<m->data<<" survives. (Winner)\n";
}
int main(){
    int n,k;
    cin>>n>>k;
    potato_problem(n,k);
    return 0;
}