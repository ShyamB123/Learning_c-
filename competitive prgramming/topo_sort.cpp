#include <bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
#define F first
#define S second
#define pb push_back
#define mp make_pair

#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define nl '\n'

using namespace std;

vector<set<int>> adj(26);
vector<bool> visited(26,false);
// set<int> vertices;
int n = 26;
bool ok = false;
list<int> order;

void dfs2(int src)
{
    visited[src] = true;

    for(auto it:adj[src])
    {
        if(visited[it] == false)
        {
            dfs2(it);
        }
    }
    order.push_front(src);
}

void topo_sort()
{
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()>0 && visited[i] == false)
        {
            dfs2(i);
            // order.push_front(i);
        }
    }
}