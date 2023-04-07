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
vector<bool> visited(N,false);
vi depth(N,0);
vi ans(N,0);
vi temp(N,0);


int cal_depth(int src)
{
    visited[src] = true;
    depth[src] = 0;

    int cur = 0;
    for(auto it:adj[src])
    {
        if(visited[it] == false)
        {
            cur = max(cur,cal_depth(it));
        }
    }

    depth[src] = cur;

    return depth[src] + 1;
}


void dfs(int src,int par_ans)
{
    visited[src] = true;

    // we calculate all the maxs for the children

    vii v;
    for(auto it:adj[src])
    {
        if(visited[it] == false)
            v.pb({ans[it],it});
    }

    vi pre(v.size()),suf(v.size());

    int cur = 0;

    for(int i =0;i<v.size();i++)
    {
        pre[i] = cur;
        cur = max(cur,v[i].F);
    }

    cur = 0;

    for(int i = v.size() -1 ;i>=0 ; i--)
    {
        suf[i] = cur;
        cur = max(cur,v[i].F);
    }

    
    for(int i=0;i<v.size();i++)
    {
        // if(visited[v[i].S] == true)
        // cout <<v[i].S<<nl;
        // cout <<pre[i]<<" "<<suf[i]<<nl;

        if(i==0 && i==v.size()-1)
        {
            ans[v[i].S] = max({depth[v[i].S],1 + max(pre[i],suf[i]),1 + par_ans});
             temp[v[i].S] = max({1 + max(pre[i],suf[i]),1 + par_ans});
        }
        else
        {
            ans[v[i].S] = max({depth[v[i].S],2 + max(pre[i],suf[i]),1 + par_ans});
            temp[v[i].S] = max({2 + max(pre[i],suf[i]),1 + par_ans});
        }
            // cout<<temp[v[i].S]<<" ";
        // else
        // {
        //     ans[v[i].S] = max(depth[v[i].S],2 + max(pre[i],suf[i]));
        // }
    }

    for(auto it:adj[src])
    {
        if(visited[it] == false)
        {
            dfs(it,temp[it]);
        }
    }
}



void solve()
{
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    int x = cal_depth(1);

    // for(int i=1;i<=n;i++){
    //     cout <<depth[i]<< " ";
    // }
    // cout <<nl;

    for(int i=1;i<=n;i++){
        visited[i] = false;
        ans[i] = depth[i];
    }

    dfs(1,0);

    ans[1] = depth[1];

    // for(int i=1;i<=n;i++){
    //     cout <<temp[i]<< " ";
    // }
    // cout <<nl;
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
