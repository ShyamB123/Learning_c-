#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

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

    void dfs_helper(T src, unordered_map<T, bool> &visited, list<T> &ordering)
    {
        visited[src] = true;

        for (auto it : m[src])
        {
            if (visited[it] == false)
                dfs_helper(it, visited, ordering);
        }

        ordering.push_front(src);
    }

    void dfs()
    {
        unordered_map<T, bool> visited;
        list<T> ordering;

        for (auto it : m)
        {
            T node = it.first;
            visited[node] = false;
        }

        // calling helper function for all vertices

        for (auto it : m)
        {
            T node = it.first;
            if (visited[node] == false)
            {
                dfs_helper(node, visited, ordering);
            }
        }
        for(auto it:ordering)
        {
            cout << it << endl;
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("python", "DataPreprocessing");
    g.addEdge("python", "PyTorch");
    g.addEdge("python", "ML");
    g.addEdge("DataPreprocessing", "ML");
    g.addEdge("PyTorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecogn");
    g.addEdge("DataSet", "FaceRecogn");

    // g.print();
    g.dfs();
}