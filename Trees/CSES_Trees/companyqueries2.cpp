
#include <bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 998244353
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

bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.F > p2.F;
}

/*

*/

const int N = 2 * 1e5 + 1;
vector<vi> adj(N);
vector<vi> ans(N);
vector<vi> up(N, vector<int>(20, -1));
vector<int> level(N, 0);

void find_level(int src, int par, int l)
{
    level[src] = l;

    for (auto it : adj[src])
    {
        if (it != par)
        {
            find_level(it, src, l + 1);
        }
    }
}

void dfs(int src, int par)
{
    if (src != par)
    {
        up[src][0] = par;
        for (int i = 1; i <= 20; i++)
        {
            if (up[src][i - 1] >= 0)
                up[src][i] = up[up[src][i - 1]][i - 1];
            else
                up[src][i] = -1;
        }
    }

    for (auto it : adj[src])
    {
        if (it != par)
        {
            dfs(it, src);
        }
    }
}

int up_checker(int x, int k)
{
    bool ok = false;
    for (int i = 0; (1 << i) <= k; i++)
    {
        if (((1 << i) & k) > 0)
        {
            x = up[x][i];
            if (x == -1)
            {
                ok = true;
                break;
            }
        }
    }
    return x;
}

void solve()
{
    int n;
    cin >> n;

    int q;
    cin >> q;

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;

        adj[x].pb(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            up[i][j] = -1;
        }
    }

    find_level(1, 1, 0);
    dfs(1, 1);

    for (int qr = 0; qr < q; qr++)
    {
        int a, b;
        cin >> a >> b;

        if (level[a] < level[b])
        {
            b = up_checker(b, level[b] - level[a]);
        }
        else if (level[b] < level[a])
        {
            a = up_checker(a, level[a] - level[b]);
        }

        if (a == b)
        {
            cout << a << nl;
            continue;
        }

        for (int i = 20; i >= 0; i--)
        {
            int tempa = up[a][i];
            int tempb = up[b][i];

            if (tempa != tempb && tempa != -1 && tempb != 1)
            {
                a = tempa;
                b = tempb;
            }
        }

        a = up[a][0];

        cout << a << nl;
    }
}

int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}
