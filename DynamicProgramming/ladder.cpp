#include <bits/stdc++.h>

using namespace std;

int ladder_td(int n, int k, int *dp) // 0(n*k)
{
    // base
    if (n == 1 || n == 0)
    {
        return 1;
    }
    // if(n<0)
    // {
    //     return 0;
    // }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
            dp[n] += ladder_td(n - i, k, dp);
    }

    return dp[n];
}

int ladder_bd(int n, int k) // O(n*k)
{
    int dp[n + 1] = {0};
    dp[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                dp[i] += dp[i - j];
        }
    }

    return dp[n];
}

int optimised(int n,int k) // O(n)
{
    int dp[n+1]={0};
    dp[0] = dp[1] = 1;

    for(int i = 2;i<=k;i++)
    {
        dp[i] = 2*dp[i-1];
    }

    for(int i=k+1;i<=n;i++)
    {
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }

    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;

    int dp[n + 1] = {0};
    int ans1 = ladder_td(n, k, dp);
    cout << ans1 << endl;

    int ans2 = ladder_bd(n, k);
    cout << ans2 << endl;

    int ans3 = optimised(n, k);
    cout << ans3 << endl;
}