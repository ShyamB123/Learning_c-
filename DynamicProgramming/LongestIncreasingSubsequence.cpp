#include <bits/stdc++.h>

using namespace std;

int lis2(int *a, int n)
{
    // int length;
    int dp[n + 1] = {};
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int length = 0; length < n; length++)
        {
            if (dp[length] < a[i] and a[i] < dp[length + 1])
                dp[length + 1] = a[i];
        }
    }
    int subseq = 0;
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
        if (dp[i] != INT_MAX)
            subseq = i;
        // m = max(m,dp[i]);
    }
    cout << endl;
    return subseq;
}

int lis2_opt(int *a, int n)
{
    // int length;
    int dp[n + 1] = {};
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // for(int length = 0 ; length < n ; length ++)

        //     if(dp[length]<a[i] and a[i]<dp[length+1])
        //         dp[length + 1] = a[i];
        int length = upper_bound(dp,dp+n,a[i]) - dp;

        if(dp[length-1]<a[i] and a[i] < dp[length]) 
            dp[length] = a[i];
        
        
        
    }
    int subseq = 0;
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
        if (dp[i] != INT_MAX)
            subseq = i;
         
    }
    cout << endl;
    return subseq;
}

int lis(int *a, int n)
{
    int dp[n] = {1};

    for (int i = 1; i < n; i++)
    {
        int maxsum = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                dp[i] = dp[j] + 1;

            dp[i] = max(maxsum, dp[i]);
        }
    }
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        maxsum = max(dp[i], maxsum);
    }

    return maxsum;
}

int main()
{
    int a[] = {1, 5, 2, 3, 4, 9, 6, 1};
    int n = sizeof(a) / sizeof(int);

    int ans1 = lis(a, n);
    cout << ans1 << endl;

    int ans2 = lis2(a, n);
    cout << ans2 << endl;

    int ans3 = lis2_opt(a, n);
    cout << ans3 << endl;
}