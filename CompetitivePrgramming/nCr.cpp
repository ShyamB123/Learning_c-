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

ll binexp(ll a, ll b)
{
    ll result = 1;
    while (b)
    {
        if (b & 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}
vector<ll> infact, fact;

void fill_inverse_fact_fact(ll n)
{
    infact.resize(n + 1);
    fact.resize(n + 1);
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        // fact[i] = mul(fact[i-1],i);
        fact[i] = (fact[i - 1] * i) % mod;
    }
    infact[n] = binexp(fact[n], mod - 2);
    infact[0] = 1;
    for (ll i = n - 1; i >= 1; i--)
    {
        // infact[i] = mul(i+1,infact[i+1]);
        infact[i] = ((i + 1) * infact[i + 1]) % mod;
    }
}

long long ncr(ll n, ll k)
{
    return fact[n] * infact[k] % mod * infact[n - k] % mod;
}