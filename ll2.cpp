#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
node* head;

    void createList(int n){
        int k;
        cin>>k;
        head=new node();
        head->data=k;
        head->next=head;
        node* temp=head;
        for(int i=1; i<n; i++){
            cin>>k;
            node* newnode=new node();
            newnode->data=k;
            newnode->next=NULL;
            temp->next=newnode;
            temp=temp->next;
        }
    }
    void print()
    {
        struct node *ptr;
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d", ptr->data);
            printf("\n");
            ptr=ptr->next;
        }
    }
    void insertAtNthPosition(int a,int p){
        node* temp=head;
        node* temp1=new node();
        temp1->data=k;
        temp1->next=NULL;
        for(int i=0; i<p-2; i++){
            temp=temp->next;
        }
        temp1->next=temp->next;
        temp->next=temp1;
    }

int main(){
    head=NULL;
    int i,k,p,n,a;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter the elts in the ll:"<<endl;
    createList(n);
    switch(k){
        case 1:
            cout<<"enter the elt and position resp:";
            cin>>a>>p;
            break;
        case 2:
            cout<<"enter the position that u want to delete:";
            ci
    }
