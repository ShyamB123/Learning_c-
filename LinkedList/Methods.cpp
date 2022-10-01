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

node* take_input()
{
    int d;
     cin>>d;
    node * head = NULL;
    while(d!=-1)
    {
         insertHead(head,d);
         cin>>d;
    }
    return head;
}

istream& operator>>(istream& is,node* &head)
{
    head = take_input();
    return is;
} 

ostream& operator<<(ostream& os , node* & head)
{
    print(head);
    return os;
}

void reverse(node*& head)
{
    node* current =head;
    node* prev = NULL;
    node* next;

    while(current!=NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head= prev;
}

node* RecReverse(node* head)
{
    if(head->link == NULL)
    {
        
        return head;
    }
     node*TempHead = RecReverse(head->link);

    node* temp = head->link;
    temp->link = head;
    head->link = NULL;

    return TempHead;

    
}

node*  midpoint(node* head)
{
    if(head==NULL or head->link == NULL)
    {
        return head;
    }

    node* temp1 = head->link;
    node* temp2 = head;

    while(temp1->link != NULL && temp1!= NULL)
    {
        temp1= temp1->link->link;
        temp2 = temp2->link;
        
    }
    return temp2;
}

node* Kth_node_from_end(node* head,int k)
{
    node* fast = head;
    node* slow=  head;
    for(int i =1 ;i<k;i++)
    {
        fast = fast->link;
    }
    while(fast->link!=NULL)
    {
        fast = fast->link;
        slow = slow->link;
    }
    return slow;
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

    //node * head2 = take_input();
    //print(head2);

    node* temp;
    cin>>temp;
    cout << temp;

    reverse(temp);
    cout << temp;

    node * temp2 = RecReverse(temp);
    cout << temp2;
    
    node * mid_point = midpoint(temp2);
    cout << "Middle value:"<<mid_point->data<<endl;

    node * l = Kth_node_from_end(temp2,2);
    cout << "2nd value from end:"<<l->data<<endl;
}