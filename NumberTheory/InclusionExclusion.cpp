#include<bits/stdc++.h>
#define ll long long 

using namespace std;

int main()
{
    int primes[] = {2,3,5,7,11,13,17,19};

    ll subsets = 1<<8 -1;

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        ll ans = 0;

        for(ll i =1;i<=subsets;i++)
        {
            ll denom = 1;
            ll set_bits = __builtin_popcount(i);

            for(int j =0;j<=7;j++)
            {
                if(i&(1<<j))
                {
                    denom *= primes[j];
                }
            }
            
            if(set_bits&1)
            {
                ans += n/denom;
            }
            else
            {
                ans -= n/denom;
            }
        }
        cout << ans<<endl;
    }

    

}