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
vector<vector<int>> dp(N, vector<int>(3, -1));

vi dfs(int src)
{
    visited[src] = true;

    if (dp[src][0] != -1)
    {
        return dp[src];
    }

    // we need to find three things
    // 1. the longest path not including root
    // 2. the longest path including root
    // 3. the longest path starting from root

    vector<vi> v;
    for (auto it : adj[src])
    {
        if (visited[it] == false)
        {
            vi temp = dfs(it);
            v.pb(temp);
        }
    }
    dp[src][0] = dp[src][1] = dp[src][2] = 0;

    int len = v.size();

    // 1. the longest path not including root
    for (int i = 0; i < len; i++)
    {
        dp[src][0] = max({dp[src][0], v[i][0], v[i][1], v[i][2]});
    }

    // if(v.size()>=1)
    // {
    vi longest;
    for (int i = 0; i < len; i++)
    {
        longest.pb(v[i][2]);
    }

    sort(all(longest));
    reverse(all(longest));

    // 2. the longest path including root
    if (longest.size() >= 2)
        dp[src][1] = longest[0] + longest[1] + 2;
    else
        dp[src][1] = 0;

    // 3. the longest path starting from root
    if (longest.size() >= 1)
    {
        dp[src][2] = longest[0] + 1;
    }
    else
    {
        dp[src][2] = 0;
    }
    // }
    // cout <<"vertex:"<<src<<":"<<dp[src][0]<<" "<<dp[src][1]<<" "<<dp[src][2]<<nl;
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
    for (int i = 1; i <= n; i++)
    {

        visited[i] = false;
    }
    vi ans = dfs(1);
    cout << max({ans[0], ans[1], ans[2]}) << nl;

    // cout <<nl;
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
