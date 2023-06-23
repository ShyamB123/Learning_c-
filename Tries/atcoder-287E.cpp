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

vector<vi> adj(1,vi(26,0));
vector<vi> val(1,vi(26,0));


void solve()
{
    int n;
    cin>>n;

    vector<string> v;
    map<string ,int> m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;

        v.pb(s);
        m[s]++;

       int node = 0;
        for(auto it:s)
        {
            
            if(adj[node][int(it - 'a')] == 0)
            {
                adj.pb(vi(26,0));
                val.pb(vi(26,0));
                adj[node][int(it - 'a')] = adj.size() - 1;
            }
            
            node = adj[node][int(it - 'a')];
            val[node][int(it - 'a')]++;
        }
    }


    for(int i =0;i<n;i++)
    {
        string s = v[i];

        int ans = 0;
        int node = 0;

        for(auto it:s)
        {
            node = adj[node][int(it - 'a')];
            int count =0 ;
            ll tempval = 0;
            for(int j =0;j<26;j++)
            {
                tempval += val[node][j];
            }

            if(tempval>1)
            {
                ans++;
            }
            else
            {
                break;
            }
            
        }
        cout << ans<<nl;
    }
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}