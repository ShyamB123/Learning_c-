#include <bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 998244353
#define inf 1e9
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

bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/

const int N = 1e5 + 1e5 + 1;

vector<vi> adj(N);
// vector<int> dp(N,0);
vector<bool> visited(N, false);
vector<vector<int>> dp(N, vector<int>(2, -1));

vi dfs(int src)
{
    visited[src] = true;

    if (dp[src][0] != -1)
    {
        return dp[src];
    }

    dp[src][0] = dp[src][1] = 0;
    vector<vi> v;
    for (auto it : adj[src])
    {
        // lets calculate when we dont take the vertex src
        if (visited[it] == false)
        {
            vi temp = dfs(it);
            v.pb(temp);
            dp[src][0] += max(temp[0], temp[1]);
        }
    }

    // for(auto it : adj[src])
    // {

    //         vi temp = dfs(it);

    // }

    int pre[v.size()], suf[v.size()];

    int len = v.size();

    int cur = 0;
    for (int i = 0; i < len; i++)
    {
        pre[i] = cur;
        cur += max(v[i][0], v[i][1]);
    }

    // int suf = 0;
    cur = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        suf[i] = cur;
        cur += max(v[i][0], v[i][1]);
    }

    int tempans = 0;
    for (int i = 0; i < len; i++)
    {

        tempans = v[i][0] + pre[i] + suf[i] + 1;
        dp[src][1] = max(dp[src][1], tempans);
    }
    return dp[src];
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    vi ans = dfs(1);
    cout << max(ans[0], ans[1]) << nl;

    cout << nl;
}

int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    // ll t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
}
