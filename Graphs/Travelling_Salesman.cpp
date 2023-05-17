#include <bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e12
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

ll n;
vector<vi> adj(20);
const ll N = 3 * 1e5;

ll dp[20][N];

ll cost(ll x, ll y)
{
    return abs(adj[x][0] - adj[y][0]) + abs(adj[x][1] - adj[y][1]) + max(0, adj[y][2] - adj[x][2]);
}

void solve()
{
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[i].pb(a);
        adj[i].pb(b);
        adj[i].pb(c);
    }

    memset(dp, 0, sizeof(dp));

    for (ll i = 1; i < n; i++)
    {
        dp[i][0] = abs(adj[0][0] - adj[i][0]) + abs(adj[0][1] - adj[i][1]) + max(0, adj[0][2] - adj[i][2]);
    }
    for (ll j = 1; j < (1 << n); j++)
    {
        for (ll i = 0; i < n; i++)
        {
            dp[i][j] = inf;
            ll num = j;

            for (ll k = 0; (1 << k) < (1 << n); k++)
            {
                if ((num & (1 << k)) > 0)
                {
                    ll rem = num ^ (1 << k);
                    dp[i][j] = min(dp[i][j], dp[k][rem] + cost(i, k));
                }
            }
        }
    }

    cout << dp[0][(1 << n) - 1] << nl;
}

int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}