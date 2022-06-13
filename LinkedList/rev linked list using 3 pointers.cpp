#include <iostream>

using namespace std;

struct node
{
    int data;
    node* link;
};

node * head ;//head pointer

void Insert(int x);
void print();
void rev();

int main()
{
    head=NULL;
    Insert(2);
    Insert(3);
    Insert(5);
    Insert(8);
    print();
    rev();
    print();
    
}


void Insert(int x)
{
    node * temp = new node();
    temp->data=x;
    temp->link=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    node* temp2=head;
    while(temp2->link!=NULL)
    {
        temp2=temp2->link;
    }
    temp2->link=temp;

}

void print ()
{
    node* temp=head;

    while(temp!=NULL)
    {
        cout<< temp->data <<" ";
        temp=temp->link;
    }
    cout<<"\n";

}

void rev()
{
    node *prev,*cur,*next;

    cur=head;
    prev=NULL;
    while(cur!=NULL){
        next=cur->link;
        cur->link=prev;
        prev=cur;
        cur=next;
    }
    head =prev;
}