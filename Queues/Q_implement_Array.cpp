#include<iostream>

using namespace std;

class queue
{
    int * arr;
    int f,r,cs,ms;

    public:

    queue(int ds=5)//if no parameter 5 is considered default
    {
        arr = new int[ds];
        ms=ds;
        cs=0;
        f=0;
        r=ms-1; 
    }

    bool full()
    {
        return cs==ms;
    }

    bool empty()
    {
        return cs==0;
    }

    void push(int data)
    {
        if(!full())
        {
        r=(r+1)%ms;
        arr[r] = data;
        cs++;
        }
    }

    void pop()
    {
        if(!empty())
        {
            f= (f+1)%ms;
            cs--;
        }
    }

    int top()
    {
        return arr[f];
    }


};

int main()
{
    queue q(10);
    for(int i=1;i<=6;i++)
    {
        q.push(i);
    }

    q.pop();
    q.pop();
    q.push(9);

    while(!q.empty())
    {
        cout << q.top()<<" ";
        q.pop();
        
    }
}