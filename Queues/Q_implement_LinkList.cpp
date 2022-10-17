#include<iostream>
#include<list>

using namespace std;

class queue
{

    private:
    int cs;
    list<int> l;

    public:

    queue()
    {
        cs=0;
    }
    bool isEmpty()
    {
        return cs==0;
    }

    void push(int data)
    {
        l.push_back(data);
        cs++;
    }

    void pop()
    {
        if(!isEmpty())
        {
            cs--;
            l.pop_front();
        }
    }

    int front()
    {
            return l.front();
        
    }


};

int main()
{
    queue q;

    for(int i=0;i<=15;i++)
    {
        q.push(i*i);
    }

   // q.pop();

    while(!q.isEmpty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}