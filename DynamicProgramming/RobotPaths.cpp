#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

void solve()
{
    ll m, n, p;
    cin >> m >> n >> p;

    ll a[m][n];
    ll x, y;

    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            a[i][j] = 1;
        }
    }

    for (ll i = 1; i <= p; i++)
    {
        cin >> x >> y;
        a[x - 1][y - 1] = 0;
    }
    if (a[0][0] == 0)
    {
        cout << 0 << endl;
        return;
    }

    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                a[i][j] = 1;
            }
            else if (i == 0 && j != 0 && a[i][j] != 0)
            {
                a[i][j] = a[i][j - 1] % mod;
            }
            else if (i != 0 && j == 0 && a[i][j] != 0)
            {
                a[i][j] = a[i - 1][j] % mod;
            }
            else if (a[i][j] != 0)
            {
                a[i][j] = (a[i - 1][j] + a[i][j - 1]) % mod;
            }
        }
    }
    cout << a[m - 1][n - 1] % mod << endl;
}

int main()
{
    solve();
}