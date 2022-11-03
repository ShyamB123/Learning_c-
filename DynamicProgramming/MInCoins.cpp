#include<bits/stdc++.h>
#define max 100000

using namespace std;

int mincoins_td(int n,int * coins,int t,int * dp)
{

    if(n==0)
    {
        return 0;
    }

    if(dp[n]!=0)
    {
        return dp[n];
    }

    int temp = max;
    for(int i=0;i<t;i++)
    {
        if(n-coins[i]>=0)
        {
        int subans = mincoins_td(n-coins[i],coins,t,dp)+1;
        temp = min(temp,subans);
        }

    }
    dp[n] = temp;
    return dp[n];

}

int mincoins_bottomup(int n,int * coins,int t,int *dp)
{
    int temp = max;
    int ans = max;
    for(int j=1;j<=n;j++)
    {
    
        temp  = max;
        for(int i=0;i<t;i++)
        {
            
            ans = max;
            if(j-coins[i]>=0)
            {
                ans = dp[j-coins[i]];
                //cout << "ans:"<<ans<<endl;
            }
            temp = min(temp,ans);
           // cout << "temp:"<<temp<<endl;
            
        }
        dp[j] = temp + 1;
       // cout << "dp["<<j<<"] = "<<dp[j]<<endl;
    }
    return dp[n];
    
}

int main()
{
    int n;
    cin>>n;

    int t;
    cin>>t;

    int coins[t];
    for(int i=0;i<t;i++)
    {
        cin>>coins[i];
    }
    int dp[100]={0};

    int ans1 = mincoins_td(n,coins,t,dp);
    cout << ans1<<endl;

    int dp2[n+1] = {0};
    int ans2 = mincoins_bottomup(n,coins,t,dp2);
    cout << ans2 << endl;

}