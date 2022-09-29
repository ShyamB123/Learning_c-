#include<bits/stdc++.h>

using namespace std;

class node
{
    public:

      int data;
      node* link;
    node()
    {
        data = 0;
        link = NULL;

    }
    node(int x)
    {
        data= x;
        link = NULL;

    }

    int get_data(node * head)
    {
        return head->data;
    }
};
void insertHead(node *& head,int x)
    {

        node* n = new node(x);
        n->link = head;
        head = n;    
    }

void insertMiddle(node* &head,int x,int pos)
    {
        node*n = new node(x);

        node * temp = head;
        for(int  i= 1 ;i<pos-1;i++)
        {
            temp = temp->link;
        }
        n->link =temp->link;
        temp->link = n; 
    }

void print(node* head)
    {
        while(head!=NULL)
        {
            cout << head->data << "->";
            head = head->link;
        }
        cout << endl;

    }

void deletion(node* &head,int pos)
{
    node* temp = head;
    if(pos==1)
    {
        head= temp->link;
        delete temp;
        return;

    }

    for(int i = 1 ;i < pos -1 ;i++)
    {
        temp = temp->link;
    }
    node* temp2 =temp->link;
    temp ->link = temp2->link;
    delete temp2;
    

}

bool search(node* head , int key)
{
    
    while(head!=NULL)
    {
        if(head->data == key)
        {
            return true;
        }

        head = head->link;
    }    

    return false;

}


bool RecSearch(node * head,int key)
{
    if(head== NULL)
    {
        return false;
    }

    if(head->data == key)
    {
        return true;
    }
    else{
        return RecSearch(head->link,key);
    }
}

int main()
{
    node* head =NULL;

    insertHead(head,2);
    insertHead(head,3);
    insertHead(head,4);
    insertMiddle(head,5,1);

    print(head);

    deletion(head,1);

    print(head);

    if(search(head,5)){
        cout << "5 is present"<<endl;
    }
    if(RecSearch(head,3)){
        cout << "3 is present"<<endl;
    }

}