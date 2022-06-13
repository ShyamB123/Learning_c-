#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};
node * head;

void Insert(int x);
void print();
void Delete(int n);

int main()
{
    head = NULL;

    Insert(2);
    Insert(3);
    Insert(5);
    Insert(8);
    print();

    int n;
    cout<< "enter the postion to be deleted:";
    cin>>n;

    Delete(n);
    print();
}


void Insert(int x)
{
    node * temp1 = new node();
    temp1->data=x;
    temp1->next=NULL;

    node* temp2=head;

     if(head==NULL){
        head=temp1;
        return;
     }
    while(temp2->next!=NULL){

        temp2=temp2->next;
    }


    temp2->next =temp1;

}