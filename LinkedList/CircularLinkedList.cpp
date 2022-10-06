#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node * link;

    //constructor
    node()
    {
        data = 0;
        link = NULL;
    }
    node(int e)
    {
        data = e;
        link = NULL;
    }
};

void insert(node*&head , int d)
{
    node* n = new node(d);

    n->link = head;
    node*temp = head;
    if(temp!=NULL)
    {
    while(temp->link!=head)
    {
        temp = temp->link;
    }
        temp->link = n;

    }
    else{
        n->link = n;
    }
    head = n;

}

void print(node* head)
{
    node* pntr = head;
    do{
        cout << pntr->data<<"->";
        pntr = pntr->link;
    }while(pntr != head);
    cout << endl;

   

}

node* getnode(node* head,int d)
{
    node * temp = head;
    while(temp->link!=head)
    {
        if(temp->data == d)
        {
            return temp;
        }
        temp = temp->link;
    }
    temp=temp->link;
    if(temp->data==d)
    {
        return temp;
    }
    return NULL;
}

void deletenode(node* &head,int d)
{
    node* del = getnode(head,d);

    if(del == NULL)
    {
        return;
    }

    if(del == head)
    {
        head = head->link;
    }
    node*temp = head;

    while(temp->link!= del)
    {
        temp = temp->link;
    }

    temp->link = del->link;
    delete del;

}

int main()
{
    
     node* head = NULL;
     insert(head,10);
     insert(head,20);
     insert(head,30);
     insert(head,40);
     insert(head,50);

     print(head);

     deletenode(head,30);
     deletenode(head,50);
     print(head);

}