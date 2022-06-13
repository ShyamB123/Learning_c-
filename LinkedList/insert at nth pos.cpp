#include <iostream>
using namespace std;
using namespace std;

void Insert(int x);
void Insertn(int x,int n);
void print();
void Delete(int n);


struct node
{
   int data;
   node* next;

};

node* head;//head node

int main()
{
    head = NULL;
    Insertn(2,1);// 2
    Insertn(3,2);// 2 3
    Insertn(5,1);// 5 2 3
    Insertn(8,2);// 5 8 2 3

    print();

   // cout<<"enter the position to be deleted:";
   // int n;
    //cin>>n;
   // Delete(n);
   // print();
}

void Insert(int x)
{
    node * last= new node();
    last->data=x;
    last->next=NULL;

    node* temp;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
    }
    temp=last;

    last->next= head;
    head= last;
}

void print()
{
    node*temp;
    temp=head;

    while(temp!=NULL){
        cout<< temp->data << " ";
        temp=temp->next;

    }
    cout << "\n";
}

void Insertn(int x,int n)
{
    node * temp1 = new node();
    temp1->data=x;
    temp1->next = NULL;
    if(n==1)
    {
        temp1->next = head;
        head= temp1;
        return;
        }
    node * temp2= head;
    for(int i =1;i<n-1;i++){
        temp2=temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}