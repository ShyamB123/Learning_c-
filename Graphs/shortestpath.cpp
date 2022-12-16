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
        unordered_map<T,int> dist;
        queue<T> q;

        q.push(srch);
        dist[srch] = 0;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            //cout << node<<" ";
            for(auto nbr:m[node])
            {
                if(dist.find(nbr) == dist.end())
                {
                    q.push(nbr);
                    dist[nbr] = dist[node]+1;
                }

            }
        }
        cout << endl;

        for(auto it:dist)
        {
            cout<<"node "<<it.first<<" is at distance "<<it.second<<" from search node"<<endl;
        }

    }

};

int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    //g.print();
    g.bfs(0);


}