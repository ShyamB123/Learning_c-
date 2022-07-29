#include <iostream>
#include<stack>

using namespace std;

void Insert(int x);
void Reverse();
void print();

struct node
{
    int data;
    node * link;
};
node* head;

int main()
{
    head = NULL;
    Insert(2);
    Insert(3);
    Insert(5);
    Insert(8);
    print();
    Reverse();
    print();
}

void Insert(int x)
{
    node * temp=new node();
    temp->data=x;
    temp->link=head;
    head=temp;
}
 void Reverse()
 {
     stack<node *> S;

     node * temp=head;
     if(head==NULL){
        return;
     }
     while(temp!=NULL){
        S.push(temp);
        temp=temp->link;
     }

     head=S.top();
     temp=head;
     S.pop();
     while(!(S.empty())){
        temp->link=S.top();
        temp=temp->link;
        S.pop();
     }

     temp->link=NULL;
 }

 void print()
 {
     node * temp=head;
     while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->link;

     }
     cout<<"\n";
 }