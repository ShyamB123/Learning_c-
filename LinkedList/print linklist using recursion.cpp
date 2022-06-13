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
void Rec_Print(node*p);
void Rev_Rec_Print(node*p);

int main()
{
    head=NULL;
    Insert(2);
    Insert(3);
    Insert(5);
    Insert(8);

//    print();
    Rec_Print(head);
    Rev_Rec_Print(head);
    //print();

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

void Rec_Print(node * pntr)
{
    if(pntr!=NULL){
        cout<<pntr->data<<" ";
        Rec_Print(pntr->link);

    }
    else{
            cout<<"\n";
        return;
    }
}
void Rev_Rec_Print(node * pntr)
{
    if(pntr!=NULL){
        Rev_Rec_Print(pntr->link);
        cout<<pntr->data<<" ";

    }
    else{
        return;
    }
}