#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <map>

using namespace std;

template <typename T>
class Graph
{
    unordered_map<T, list<T>> m;

public:
    void addEdge(T x, T y)
    {
        m[x].push_back(y);
    }

    int bfs(T srch, T dest)
    {
        map<T, int> dist;
        unordered_map<T, T> parent;
        queue<T> q;

        q.push(srch);
        dist[srch] = 0;
        parent[srch] = srch;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (auto nbr : m[node])
            {
                if (dist.find(nbr) == dist.end())
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                }
            }
        }

        T node = dest;
        while (node != srch)
        {
            cout << node << "<-";
            node = parent[node];
        }
        cout << srch;
        cout << endl;

        return dist[dest];
    }
};

int main()
{

    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;

    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];
            
            if (j <= 36)
            {
                g.addEdge(i, j);
            }
        }
    }

    int shortest_path = g.bfs(0, 36);
    cout << shortest_path << endl;
}