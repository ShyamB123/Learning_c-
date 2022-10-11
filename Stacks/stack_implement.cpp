#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class stack
{
    private:
    vector<T> v;

    public:
    bool is_empty()
     {
        return v.size() == 0;
     }
     void push(T data)
     {
        v.push_back(data);
     }
     void pop()
     {
        if(!is_empty())
        v.pop_back();
     }
     T top()
     {
        return v[v.size()-1];
     }
     
     
     };

int main()
{
    stack<int> s;
    for(int i =1;i<=6;i++)
    {
        s.push(i*i);
    }
    while(!s.is_empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

}