#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

void prime_sieve(int * arr)
{
  
    arr[0] = arr[1] = 0;
    arr[2] = 1;

 
    for(int i = 3;i<10000;i += 2)
    {
        arr[i] = 1;
    }

    for(int i = 3;i<10000;i += 2)
    {
        if(arr[i]==0)
            continue;

       
        for(int j = i*i;j<10000;j += i) 
        {
            arr[j] = 0;
        }
    }
}

int no_of_divisors(int n,vector<int> v)
{
    //vector<pair<int, int>> v;
    int ans=1;
    int i = 0;
    while(v[i]*v[i]<=n)
    {
        //cout <<"ith element of vector"<<v[i]<<endl;
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
            ans *= count+1;
        }
        i++;
    }

    if (n != 1)
    {
       ans = ans * 2;
    }

    return ans;
    
}

// void solve(vector<ll> v)
// {
//     // for(auto it:v)
//     // {
//     //     cout << it<<" ";
//     // }
//     ll n;
//     cin >> n;

//     ll a[n];
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     bool ans;
//     unordered_map<ll, ll> m;

//     for(ll i = 0;i<n;i++)
//     {
//             ans = factor(a[i],m,v);
//             if(ans == true)
//             {
//                 cout << "yes"<<endl;
//                 return;
//             }
        
        
//     }
//     // for(auto it = m.begin();it!=m.end();it++)
//     // {

//     //     cout << it->first<< "="<<it->second<<endl;
//     // }
//     // if(ans == true)
//     // {
//     //     cout << "yes"<<endl;
//     // }
//     // else
//     // {
//         cout << "no"<<endl;
//    // }
    
// }

int main()
{
    int t;
    cin >> t;
    int arr[100005];
    vector<int> v;
    
    prime_sieve(arr);
    for(int i =0;i<100005;i++)
    {
        if(arr[i]==1)
        {
            v.push_back(i);
        }
    }
    int n,finalans;
    

    while(t--)
    {
        cin>>n;
        finalans = no_of_divisors(n,v);
        cout << finalans<<endl;
        
    }
    
}