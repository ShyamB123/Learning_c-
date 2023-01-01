#include <bits/stdc++.h>
using namespace std;

class Graph
{
    // edge list
    list<pair<int, int>> l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int x, int y)
    {
        l.push_back(make_pair(x, y));
    }

    int find(int i, int *parent)
    {
        if (parent[i] == -1)
        {
            return i;
        }

        return find(parent[i], parent);
    }

    void union_set(int x, int y, int *parent)
    {
        int s1 = find(x, parent);
        int s2 = find(y, parent);

        if (s1 != s2)
        {
            parent[s2] = s1;
        }
    }

    bool isCycle()
    {
        int *parent = new int[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }

        for (auto p : l)
        {
            int x = find(p.first, parent);
            int y = find(p.second, parent);

            if (x != y)
            {
                union_set(x, y, parent);
            }
            else
            {
                cout << "both "<<p.first<<" and "<<p.second<<" have same parent "<<x<<endl;
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};

int main()
{

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);

    if (g.isCycle())
    {
        cout << "cycle is present!" << endl;
    }
    else
    {
        cout << " no Cycle is present!" << endl;
    }
}