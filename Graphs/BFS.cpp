#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

template<typename T>
class Graph
{
    unordered_map<T,list<T>> m;

    public:

    void addEdge(T x,T y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }

    void bfs(T srch)
    {
        unordered_map<T,bool> visited;
        queue<T> q;

        q.push(srch);
        visited[srch] = true;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node<<" ";
            for(auto nbr:m[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }

            }
        }

    }

};

int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,2);

    //g.print();
    g.bfs(2);


}