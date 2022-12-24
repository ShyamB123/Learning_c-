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

    void dfs_helper(T src,unordered_map<T,bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for(auto it:m[src])
        {
            if(visited[it] == false)
                dfs_helper(it,visited);
        }
    }

    void dfs(T src)
    {
        unordered_map<T,bool> visited;

        // initialising all as unvisited
        for(auto it:m)
        {
            T node  = it.first;
            visited[node] = false;
        }

        //call dfs helper
        dfs_helper(src,visited);
    }

};

int main()
{
    Graph<int> g;
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,0);


    //g.print();
    g.dfs(0);


}