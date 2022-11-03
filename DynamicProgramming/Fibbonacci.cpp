#include <bits/stdc++.h>

using namespace std;

int fibbonacci_TopDown(int n, int *dp)
{
    if (n == 0 or n == 1)
    {
        return n;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    dp[n] = fibbonacci_TopDown(n - 1, dp) + fibbonacci_TopDown(n - 2, dp);
    return dp[n];
}

int fibbonacci_BottomUp(int n, int *dp)
{
    int i;
    for (i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{

    int n;
    cin >> n;

    int dp1[100] = {0};

    int ans = fibbonacci_TopDown(n, dp1);
    cout << ans << endl;

    int dp2[n + 1];
    dp2[0] = 0;
    dp2[1] = 1;

    int ans2 = fibbonacci_BottomUp(n, dp2);

    cout << ans2 << endl;
}