#include<bits/stdc++.h>

using namespace std;

int bst_num(int n,int * dp)
{
    // if(n == 1 || n==2)
    // {
    //     return n;
    // }
    // if(n==3)
    // {
    //     return 5;
    // }
    if(dp[n]!=0)
    {
        return dp[n];
    }

    int sum =0;
    for(int i = 1;i<=n;i++)
    {
        sum = sum + bst_num(i-1,dp)*bst_num(n-i,dp);
    }
    dp[n] = sum;
    return dp[n];

}

int main()
{

    int n;
    cin>>n;

    int dp[n+1] = {0};

    dp[0]=1;
    dp[1] =1;
    dp[2] = 2;
    

    int ans = bst_num( n ,dp);
    cout << ans<<endl;
}