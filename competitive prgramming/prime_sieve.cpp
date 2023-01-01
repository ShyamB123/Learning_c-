#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007


using namespace std;

void prime_sieve(int *arr, int n)
{
    int len = n;
    arr[0] = arr[1] = 0;
    arr[2] = 1;

    for (ll i = 3; i <= len; i += 2)
    {
        arr[i] = 1;
    }

    for (ll i = 3; i <= len; i += 2)
    {
        if (arr[i] == 0)
            continue;

        for (ll j = i * i; j <= len; j += i)
        {
            arr[j] = 0;
        }
    }
}

bool factor(ll n, map<ll, ll> &m, vector<ll> v)
{
    ll i = 0;
    while (i < v.size() && (v[i] * v[i]) <= n)
    {
        ll count = 0;
        if (n % v[i] == 0)
        {
            while (n % v[i] == 0)
            {
                count++;
                n = n / v[i];
            }
        }
        if (count != 0)
        {
            if (m.find(v[i]) != m.end())
            {
                return true;
            }
            m[v[i]] = count;
        }
        i++;
    }

    if (n != 1)
    {
        if (m.find(n) != m.end())
        {
            return true;
        }
        m[n] = 1;
    }
}

int main()
{

}