#include<iostream>
#include<queue>
#include<list>

using namespace std;

class graph
{

    int V;
    list<int> * l;

    public:

    graph(int V)
    {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int x,int y)
    {
        l[x].push_back(y);

    }

    void topological_sort()
    {
        int *indeg = new int[V];

        for(int i=0;i<V;i++)
        {
            indeg[i] = 0;
        }

        for(int i =0;i<V;i++)
        {
            for( auto it:l[i])
            {
                indeg[it]++;
            }
        }

        queue<int> q;

        for(int i= 0;i<V;i++){
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty()){

            int node = q.front();
            q.pop();

            cout << node << " ";

            for(auto it : l[node])
            {
                indeg[it]--;
                if(indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }

    }
};


int main()
{
    graph g(5);

    g.addEdge(0,2);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(3,5);

    g.topological_sort();

}