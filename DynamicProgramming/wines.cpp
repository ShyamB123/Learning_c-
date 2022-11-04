#include<bits/stdc++.h>
#define M 100000

using namespace std;

int winestd(int * wines , int s , int e, int years,int dp[][M])
{
    //base case()
    if(s>e)
    {
        return 0;
    }
    if(dp[s][e]!=0)
    {
        return dp[s][e];
    }

    int op1,op2;
    op1 = wines[s]*years + winestd(wines, s+1,e,years+1,dp);
    op2  = wines[e]*years + winestd(wines,s,e-1,years+1,dp);
    dp[s][e]=max(op1,op2);

    return dp[s][e];
}

int main()
{
    int n;
    cin>>n;

    int wines[n];
    for(int i=0;i<n;i++)
    {
        cin>>wines[i];

    }

    int dp[n][M]={0};
    int ans1 = winestd(wines,0,n-1,1,dp);
    cout << ans1 << endl;
}