#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007


using namespace std;



ll binexp(ll a,ll b, ll m){
    ll result = 1;
    while(b){
        if(b&1){
            result = (result*a)%m;
        }
        a = (a*a)%m;
        b>>=1;
    }
    return result;
}

ll divmod (ll a,ll b, ll m){
    ll inv = binexp(b,m-2,m);
    ll ans = ((a%m)*(inv%m))%m;
    return ans;
}

int main()
{
    
}