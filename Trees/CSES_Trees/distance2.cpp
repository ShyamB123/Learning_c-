#include <bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e17
#define F first
#define S second
#define pb push_back
#define mp make_pair

#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int, int>>
#define vll vector<pair<ll, ll>>
#define all(a) a.begin(), a.end()
#define nl '\n'

using namespace std;

const ll N = 2 * 1e5 + 1;
ll n;

vector<vl> adj(N);
vector<ll> subtree(N, 0);
vl ans(N, 0);

ll cal_size(ll src, ll par)
{

    ll curans = 1;

    for (auto it : adj[src])
    {
        if (it != par)
        {
            curans += cal_size(it, src);
        }
    }
    return subtree[src] = curans;
}

ll dfs1(ll src, ll par)
{

    ll curans = 0;

    for (auto it : adj[src])
    {
        if (it != par)
        {
            curans += dfs1(it, src);
            curans += subtree[it];
        }
    }

    return ans[src] = curans;
}

void dfs2(ll src, ll par)
{
    if (src != par)
    {
        ll parans = ans[par];
        ll curans = ans[src];

        ll dif = parans - curans - subtree[src];
        ll remnodes = n - subtree[src] - 1;
        ll toadd = dif + remnodes;

        ans[src] += toadd + 1;
    }

    for (auto it : adj[src])
    {
        if (it != par)
        {
            dfs2(it, src);
        }
    }
}

void solve()
{

    cin >> n;

    for (ll i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll x = cal_size(1, 1);

    x = dfs1(1, 1);

    dfs2(1, 1);

    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << nl;
}

int main()
{
    solve();
}