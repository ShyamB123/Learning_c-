#include<iostream>
#include<stack>

using namespace std;

void insertBottom(stack<int>&s,int x)
{
    //base case
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int data= s.top();
    s.pop();
    insertBottom(s,x);
    s.push(data);


}
void reverseStack(stack<int>&s)
{
    //base case
    if(s.empty())
    {
        return;
    }

    int x= s.top();
    s.pop();
    reverseStack(s);
    insertBottom(s,x);
}

int main()
{
    stack <int>s ;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    stack<int> x= s;
    while(!x.empty())
    {
        cout << x.top()<< " ";
        x.pop();
    }
    cout << endl;


    reverseStack(s);
    x=s;
    while(!x.empty())
    {
        cout << x.top()<< " ";
        x.pop();
    }
    cout << endl;

}
