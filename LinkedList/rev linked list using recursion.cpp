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
void Rev_rec(node *pntr);

int main()
{
    head=NULL;
    Insert(2);
    Insert(3);
    Insert(5);
    Insert(8);

    print();
    Rev_rec(head);
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

void Rev_rec(node * pntr)
{
    if(pntr->link==NULL){
        head=pntr;
        return;
    }

    Rev_rec(pntr->link);

    node*temp;
    temp=pntr->link;
    temp->link=pntr;
    pntr->link=NULL;
}
void print()
{
    node*temp;
    temp=head;

    while(temp!=NULL){
        cout<< temp->data << " ";
        temp=temp->link;

    }
    cout << "\n";
}