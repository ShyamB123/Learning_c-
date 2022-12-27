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

    bool cycle_helper(int src, bool *visited,int parent)
    {
        visited[src] = true;

        for(auto nbr : l[src])
        {
            if(visited[nbr] == true && nbr != parent)
            {
                return true;
            }
            else if (visited[nbr] == false)
            {
                bool check = cycle_helper(nbr,visited,src);
                if(check)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool cycle_det()
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
            visited[i] = false;

        return cycle_helper(0,visited,-1);
    }
};

int main()
{
    graph g(8);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    //g.addEdge(4, 2); // back edge

    if (g.cycle_det())
    {
        cout << "it has a cycle";
    }
    else
    {
        cout << "no cycle!";
    }
}