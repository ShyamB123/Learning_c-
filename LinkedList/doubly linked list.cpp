#include <iostream>

using namespace std;

struct node
{
    int data;
    node * prev;
    node* next;
};

void InsertAtHead(int x);
void InsertAtTail(int x);
void print();
void RevPrint();

node* head;

int main()
{
    head=NULL;

    InsertAtHead(5); //5
    InsertAtHead(8); //8 5
    InsertAtTail(3); //8 5 3
    InsertAtTail(1); //8 5 3 1
    print();
    RevPrint();
}

void InsertAtHead(int x)
{
    node * temp = new node();

    if(head!=NULL)
        head->prev=temp;
    temp->data=x;
    temp->prev=NULL;
    temp->next= head;

    head=temp;
}

void InsertAtTail(int x)
{
    node*temp=new node();
    temp->data=x;
    temp->next=NULL;
    node* srch=head;

    while(srch->next!=NULL){
        srch=srch->next;

    }
    srch->next=temp;
    temp->prev=srch;
}

void print()
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<"\n";
}
void RevPrint()
{
    node * temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<"\n";
}