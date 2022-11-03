#include <bits/stdc++.h>
#define max 100000

using namespace std;

int minstep_top_down(int n, int *dp)
{
    // base case
    if (n == 1)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int op1, op2, op3;
    op1 = op2 = op3 = max;

    if (n % 3 == 0)
    {
        op1 = minstep_top_down(n / 3, dp);
    }
    if (n % 2 == 0)
    {
        op2 = minstep_top_down(n / 2, dp);
    }
    op3 = minstep_top_down(n - 1, dp);

    return min(op1, min(op2, op3)) + 1;
}

int minstep_bottom_up(int *dp, int n)
{
    int a, b, c;
    for (int i = 2; i <= n; i++)
    {
        a = b = c = max;
        if (i % 3 == 0)
        {
            a = dp[i / 3];
        }
        if (i % 2 == 0)
        {
            b = dp[i / 2];
        }

        c = dp[i - 1];

        dp[i] = min(a, min(b, c)) + 1;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    int dp[n + 1] = {0};

    int ans = minstep_top_down(n, dp);

    cout << ans << endl;

    int dp2[n+1] = {0};
    int ans2 = minstep_bottom_up(dp2, n);
    cout << ans2 << endl;
}