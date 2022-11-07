#include<bits/stdc++.h>

using namespace std;

int rod(int n,int k ,int* a,int * dp)
{
    if(n==0)
    {
        return 0;
    }
    //if()
    if(dp[n]!=0)
    {
        return dp[n];
    }

    int maxsum =0;
    int currentsum =0 ;

    for(int i=1;i<=k;i++)
    {
        if(n-i>=0){
            currentsum = a[i-1] + rod(n-i,k,a,dp);
        }

        maxsum  = max(currentsum,maxsum);
    }
    dp[n] = maxsum;
    return dp[n];

}
int main()
{
    int n,k;
    cin>>n>>k;

    int a[k];
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
    }
    int dp[n+1]={0};

    int ans = rod(n,k,a,dp);
    cout << ans << endl;


}