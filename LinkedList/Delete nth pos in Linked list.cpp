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
void Delete(int n)
{
    struct node* temp1 = head;
    if(n==1){
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i=1;i<n-1;i++)
    {
        temp1 = temp1->next;
    }
    struct node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}