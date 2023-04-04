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

unsigned ll cube_root(ll tar)
{
    unsigned ll l = 1;
    unsigned ll r = 1e7;

    unsigned ll ans = 1;

    while(l<=r)
    {
        unsigned ll mid = (l+r)/2;

        if(mid*mid*mid <= tar)
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }

    return ans;
}