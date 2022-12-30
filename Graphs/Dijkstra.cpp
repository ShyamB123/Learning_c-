#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> m;

public:
    void addEdge(T x, T y, int dist, bool bdir = true)
    {
        m[x].push_back(make_pair(y, dist));
        if (bdir)
        {
            m[y].push_back(make_pair(x, dist));
        }
    }

    void display()
    {
        for (auto p : m)
        {
            cout << p.first << "-->";
            for (auto i : p.second)
            {
                cout << "(" << i.first << "," << i.second << "),";
            }
            cout << endl;
        }
    }

    void dijkstra(T src)
    {
        unordered_map<T, int> dist;

        set<pair<int, T>> s;

        // setting all distances to be infinity
        for (auto i : m)
        {
            dist[i.first] = INT_MAX;
        }

        // setting src node dist to be 0;

        dist[src] = 0;

        // insert into set
        s.insert(make_pair(dist[src], src));

        while (!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int cur_dist = p.first;

            s.erase(s.begin());

            for (auto nbr : m[node])
            {
                // update the distance
                if (cur_dist + nbr.second < dist[nbr.first])
                {
                    // find the element
                    if (s.find(make_pair(dist[nbr.first], nbr.first)) != s.end())
                    {
                        s.erase(make_pair(dist[nbr.first], nbr.first));
                    }
                    dist[nbr.first] = cur_dist + nbr.second;
                    s.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }

        for (auto i : dist)
        {
            cout << i.first << " is at a dist of :" << i.second << endl;
        }
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);

    g.display();
    g.dijkstra(1);

    Graph<string> india;

    india.addEdge("amritsar", "delhi", 1);
    india.addEdge("amritsar", "jaipur", 4);
    india.addEdge("jaipur", "delhi", 2);
    india.addEdge("jaipur", "mumbai", 8);
    india.addEdge("bhopal", "agra", 2);
    india.addEdge("mumbai", "bhopal", 3);
    india.addEdge("agra", "delhi", 1);

    india.display();
    india.dijkstra("amritsar");
}