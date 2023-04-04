
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
#define all(a) a.begin(),a.end()
#define nl '\n'
 
using namespace std;
 
bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second<p2.second;
}
 
 
/*
 
*/
const int N = 1e5 + 1e5 + 1;
vector<vi> adj(N);
vi ans(N);
 
int dfs(int src)
{
    ans[src] = 0;
    for(auto it:adj[src])
    {
        ans[src] += dfs(it);
    }
 
    return ans[src] + 1;
}
 
void solve()
{
    int n;
    cin>>n;
 
 
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
 
        adj[x].pb(i);
    }
 
    int useless = dfs(1);
 
    for(int i=1;i<=n;i++){
        cout <<ans[i]<< " ";
    }
    cout <<nl;
 
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
