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

        parent[i] = find(parent[i], parent); // now find function of this node changed from O(n)-->O(1)

        return parent[i];
    }

    void union_set(int x, int y, int *parent, int *rank)
    {
        int s1 = find(x, parent);
        int s2 = find(y, parent);


        // union by rank
        if (s1 != s2)
        {
            if (rank[s2] < rank[s1])
            {
                parent[s2] = s1;
                rank[s1] = rank[s1] + rank[s2];
            }
            else
            {
                parent[s1] = s2;
                rank[s2] = rank[s1] + rank[s2];
            }
        }
    }

    bool isCycle()
    {
        int *parent = new int[V];
        int * rank = new int[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        for (auto p : l)
        {
            int x = find(p.first, parent);
            int y = find(p.second, parent);

            if (x != y)
            {
                union_set(x, y, parent,rank);
            }
            else
            {
                cout << "both " << p.first << " and " << p.second << " have same parent " << x << endl;
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};

int main()
{

    // optimised dsu from O(n)-->O(1)
    // used path compression 
    // used union by rank
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