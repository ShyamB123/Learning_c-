#include <bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007

using namespace std;

class dsu
{
    int V;
    vector<int> rank;
    vector<int> parent;

public:
    dsu(int vertices)
    {
        this->V = vertices;
        rank = vector<int>(vertices + 1, 1);
        parent = vector<int>(vertices + 1, 0);

        for (int i = 1; i <= vertices; i++)
        {
            parent[i] = i;
        }
    }

    int find_parent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find_parent(parent[node]);
    }
    void union_set(int a, int b)
    {
        int u = find_parent(a);
        int v = find_parent(b);

        if (u != v)
        {
            if (rank[u] < rank[v])
            {
                parent[u] = v;
                rank[v] += rank[u];
            }
            else
            {
                parent[v] = u;
                rank[u] += rank[v];
            }
        }
    }

    vector<int> get_parent()
    {
        return parent;
    }
    vector<int> get_rank()
    {
        return rank;
    }
};