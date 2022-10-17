#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue<int>q ;       // declaration

    for(int i =1;i<=10;i++)
    {
        q.push(i*i);       // push at the back of the queue

    }
  
    while(!q.empty())       // check if the queue is empty
    {
        cout << q.front()<<" ";       // returns the first element
        q.pop();    // removes the first element 
    }
}