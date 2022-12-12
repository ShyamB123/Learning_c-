#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

void prime_sieve(ll * arr)
{
  
    arr[0] = arr[1] = 0;
    arr[2] = 1;

 
    for(ll i = 3;i<10000;i += 2)
    {
        arr[i] = 1;
    }

    for(ll i = 3;i<10000;i += 2)
    {
        if(arr[i]==0)
            continue;

       
        for(ll j = i*i;j<10000;j += i) 
        {
            arr[j] = 0;
        }
    }
}

bool large_Prime(long long num,ll * arr,vector<ll> v)
{
    if(num<=100005)
    {
        if(arr[num]==1)
            return true;
        return false;
    }

    for(ll i=0;v[i]*v[i]<=num;i++)
    {
        if(num%v[i]==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll arr[100005];
    vector<ll> v;
    
    prime_sieve(arr);
    for(ll i =0;i<100005;i++)
    {
        if(arr[i]==1)
        {
            v.push_back(i);
        }
    }

    if(large_Prime(214748364,arr,v))
        cout << "it is prime!!"<<endl;
    else
        cout << "it is not prime!!"<<endl;

    
}