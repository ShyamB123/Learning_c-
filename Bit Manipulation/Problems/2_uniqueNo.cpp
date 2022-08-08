#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    int ans =0;
    for(int i = 0 ; i<n ; i++)
    {
        cin>>a[i];
        ans = ans^a[i];
    }
    int res = ans;

    int pos = 0 ;
    while(ans>0)
    {
        if(ans&1==1){
            break;
        }
        pos++;
        ans = ans>>1;

    }

    int x = 1<<pos ;
    int unq1 = 0;

    for(int i =0 ; i<n ;i++)
    {
        if(a[i]&x==1){

            unq1 = unq1^a[i];
        }
    }
    int unq2 = unq1^res;

    if(unq1>unq2)
    {
        cout<<unq2<<" "<<unq1<<endl;
    }
    else{
         cout<<unq1<<" "<<unq2<<endl;

    }
}