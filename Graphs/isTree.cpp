#include <iostream>
#include <queue>
#include <list>

using namespace std;

class graph
{

    int V;
    list<int> *l;

public:
    graph(int v)
    {
        this->V = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool isTree()
    {
        bool visited[V];
        int *parent = new int[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            visited[i] = false;
        }

        queue<int> q;

        int src = 0;
        visited[src] = true;

        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto nbr : l[node])
            {
                if (visited[nbr] == true && parent[node] != nbr)
                {
                    return false;
                }
                if (visited[nbr] == false)
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = node;
                }
            }
        }
        return true;
    }
};

int main()
{
    graph g(4);

    g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(0, 3);

    if (g.isTree())
    {
        cout << "it is a tree";
    }
    else
    {
        cout << "not a tree!";
    }
}