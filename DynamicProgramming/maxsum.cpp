#include<bits/stdc++.h>

using namespace std;

int maxsum(int * a,int n)
{
    int dp[n+1]={0};
    dp[0] = a[0]>0?a[0]:0; 

    int max_so_far = a[0];

    for(int i=1;i<n;i++)
    {
        dp[i] = dp[i-1] + a[i];
        if(dp[i]<0)
        {
            dp[i]=0;
        }
        max_so_far = max(max_so_far,dp[i]);
    }

    return max_so_far;
}

int main()
{
    int a[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(a)/sizeof(int);

    int ans = maxsum(a,n); 
    cout << ans << endl;
}